#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
CLASS_NAME="MCP"
SOURCE_FILE="$PROJECT_DIR/MCP.java"
JAVA_CMD="${JAVA_CMD:-java}"
JAVAC_CMD="${JAVAC_CMD:-javac}"

if [[ ! -f "$SOURCE_FILE" ]]; then
  echo "Error: $SOURCE_FILE not found"
  exit 1
fi

find_javafx_lib() {
  local candidates=(
    "${PATH_TO_FX:-}"
    "$HOME/javafx-sdk-21.0.6/lib"
    "$HOME/javafx-sdk-21/lib"
    "$HOME/javafx-sdk/lib"
    "/usr/share/openjfx/lib"
  )

  for candidate in "${candidates[@]}"; do
    if [[ -n "$candidate" && -d "$candidate" ]]; then
      echo "$candidate"
      return 0
    fi
  done

  return 1
}

extract_major_version() {
  local version_string="$1"
  if [[ "$version_string" =~ ^([0-9]+) ]]; then
    echo "${BASH_REMATCH[1]}"
    return 0
  fi
  echo "0"
}

find_javafx_version() {
  local props="$JAVAFX_LIB/javafx.properties"
  if [[ -f "$props" ]]; then
    local runtime_line
    runtime_line="$(grep -E '^javafx\.runtime\.version=' "$props" | head -n1 || true)"
    runtime_line="${runtime_line#javafx.runtime.version=}"
    echo "$runtime_line"
    return 0
  fi
  echo "unknown"
}

find_java_major_from_cmd() {
  local cmd="$1"
  local first_line
  first_line="$($cmd -version 2>&1 | head -n1 | tr -d '"' || true)"
  local number_part
  number_part="$(echo "$first_line" | grep -Eo '[0-9]+(\.[0-9]+)?' | head -n1 || true)"
  extract_major_version "$number_part"
}

choose_compatible_jdk() {
  local javafx_version
  javafx_version="$(find_javafx_version)"
  local javafx_major
  javafx_major="$(extract_major_version "$javafx_version")"
  local java_major
  java_major="$(find_java_major_from_cmd "$JAVA_CMD")"

  if [[ "$javafx_major" -le 11 && "$java_major" -ge 24 ]]; then
    JAVA_COMPAT_NOTE="JavaFX $javafx_major with Java $java_major can be unstable; set PREFER_JAVA21=1 to try Java 21 runtime."
    if [[ "${PREFER_JAVA21:-0}" != "1" ]]; then
      return 0
    fi

    local jdk21_candidates=(
      "/usr/lib/jvm/java-21-openjdk-amd64/bin"
      "/usr/lib/jvm/java-1.21.0-openjdk-amd64/bin"
    )

    for jdk21_bin in "${jdk21_candidates[@]}"; do
      if [[ -x "$jdk21_bin/java" ]]; then
        JAVA_CMD="$jdk21_bin/java"
        if [[ -x "$jdk21_bin/javac" ]]; then
          JAVAC_CMD="$jdk21_bin/javac"
        fi
        break
      fi
    done

    if [[ "$JAVA_CMD" == "java" ]] && command -v java21 >/dev/null 2>&1; then
      JAVA_CMD="$(command -v java21)"
    fi
  fi
}

JAVAFX_LIB="$(find_javafx_lib || true)"
if [[ -z "$JAVAFX_LIB" ]]; then
  cat <<'EOF'
Error: JavaFX SDK lib directory not found.

Set PATH_TO_FX and try again, for example:
  export PATH_TO_FX="$HOME/javafx-sdk-21.0.6/lib"
  ./launch_mcp.sh
EOF
  exit 1
fi

choose_compatible_jdk

JAVA_MAJOR="$(find_java_major_from_cmd "$JAVA_CMD")"
JAVAC_MAJOR="$(find_java_major_from_cmd "$JAVAC_CMD")"
JAVAFX_VERSION="$(find_javafx_version)"

JAVA_EXTRA_OPTS=()
if [[ "$JAVA_MAJOR" -ge 24 ]]; then
  JAVA_EXTRA_OPTS+=("--enable-native-access=javafx.graphics")
fi

PRISM_OPTS=("-Dprism.order=sw")

compile() {
  local release_opts=()
  if [[ "$JAVAC_MAJOR" -gt "$JAVA_MAJOR" && "$JAVA_MAJOR" -gt 0 ]]; then
    release_opts=(--release "$JAVA_MAJOR")
  fi

  "$JAVAC_CMD" "${release_opts[@]}" --module-path "$JAVAFX_LIB" --add-modules javafx.controls "$SOURCE_FILE"
}

run_app() {
  if [[ -z "${DISPLAY:-}" && -z "${WAYLAND_DISPLAY:-}" ]]; then
    cat <<'EOF'
Error: No graphical display detected.

Start an X11/Wayland desktop session, or set DISPLAY appropriately.
You can still compile with:
  ./launch_mcp.sh build
EOF
    exit 1
  fi

  "$JAVA_CMD" \
    "${JAVA_EXTRA_OPTS[@]}" \
    "${PRISM_OPTS[@]}" \
    --module-path "$JAVAFX_LIB" \
    --add-modules javafx.controls \
    -cp "$PROJECT_DIR" \
    "$CLASS_NAME"
}

case "${1:-run}" in
  build|--build|--build-only)
    echo "JavaFX: $JAVAFX_LIB ($JAVAFX_VERSION)"
    echo "JDK: $JAVA_CMD (major $JAVA_MAJOR)"
    echo "Javac: $JAVAC_CMD (major $JAVAC_MAJOR)"
    if [[ -n "${JAVA_COMPAT_NOTE:-}" ]]; then
      echo "Note: $JAVA_COMPAT_NOTE"
    fi
    compile
    echo "Build successful"
    ;;
  run|--run|"")
    echo "JavaFX: $JAVAFX_LIB ($JAVAFX_VERSION)"
    echo "JDK: $JAVA_CMD (major $JAVA_MAJOR)"
    echo "Javac: $JAVAC_CMD (major $JAVAC_MAJOR)"
    if [[ -n "${JAVA_COMPAT_NOTE:-}" ]]; then
      echo "Note: $JAVA_COMPAT_NOTE"
    fi

    if [[ "$JAVA_MAJOR" -ge 24 && "$(extract_major_version "$JAVAFX_VERSION")" -le 11 && "${ALLOW_UNSTABLE_JFX:-0}" != "1" ]]; then
      cat <<'EOF'
Compatibility guard:
  Detected JavaFX 11 with Java 24+.
  This combination often fails at runtime (QuantumRenderer/toolkit errors).

Recommended options:
  1) Use JavaFX 21+ SDK and set PATH_TO_FX
  2) Install a full JDK 21 and run with:
       PREFER_JAVA21=1 ./launch_mcp.sh

If you still want to try current setup:
  ALLOW_UNSTABLE_JFX=1 ./launch_mcp.sh
EOF
      exit 1
    fi

    echo "Renderer mode: software (prism.order=sw)"
    compile
    echo "Launching $CLASS_NAME..."
    if ! run_app; then
      cat <<'EOF'

JavaFX failed to initialize.
Try these checks:
  1) Run from your desktop terminal (same logged-in GUI session)
  2) Verify OpenGL/mesa stack is installed
  3) Use a matching JavaFX/JDK pair (e.g., JavaFX 21 + JDK 21)
EOF
      exit 1
    fi
    ;;
  --help|-h|help)
    cat <<EOF
Usage: $(basename "$0") [run|build]

Commands:
  run    Compile and launch the app (default)
  build  Compile only

Environment:
  PATH_TO_FX   Optional path to JavaFX lib directory
  JAVA_CMD     Optional java executable path
  JAVAC_CMD    Optional javac executable path
  PREFER_JAVA21=1  Opt-in Java 21 runtime preference for JavaFX 11 setups
EOF
    ;;
  *)
    echo "Unknown option: $1"
    echo "Try: $(basename "$0") --help"
    exit 1
    ;;
esac
