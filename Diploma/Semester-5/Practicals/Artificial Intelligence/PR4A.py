import re


class RuleBasedSystem:
    def __init__(self, rule_file):
        self.rules = self.load_rules(rule_file)
        self.symptoms = {}

    def load_rules(self, rule_file):
        rules = []
        with open(rule_file, 'r') as file:
            for line in file:   
                line = line.strip()
                match = re.match(r"IF (.+) THEN (\d+\.\d+) (.+)", line)
                if match:
                    conditions = match.group(1).split(" AND ")
                    weight = float(match.group(2))
                    conclusion = match.group(3)
                    rules.append((conditions, weight, conclusion))
                elif line.startswith("DEFAULT"):
                    match = re.match(r"DEFAULT (\d+\.\d+) (.+)", line)
                    if match:
                        weight = float(match.group(1))
                        conclusion = match.group(2)
                        rules.append(([], weight, conclusion))
        return rules

    def input_symptoms(self):
        symptoms_list = ["fever", "cough", "sore_throat", "fatigue", "headache", "chills", "sweats", "chest_pain"]
        for symptom in symptoms_list:
            self.symptoms[symptom] = input(f"Do you have {symptom.replace('_', ' ')}? (yes/no): ").lower() == "yes"

    def evaluate_condition(self, condition):
        if " OR " in condition:
            return any(self.evaluate_condition(cond.strip()) for cond in condition.split(" OR "))
        elif condition.startswith("NOT "):
            return not self.symptoms.get(condition[4:], False)
        return self.symptoms.get(condition, False)

    def diagnose(self):
        possible_diagnoses = []
        for conditions, weight, conclusion in self.rules:
            if all(self.evaluate_condition(cond) for cond in conditions):
                possible_diagnoses.append((weight, conclusion))

        if possible_diagnoses:
            possible_diagnoses.sort(reverse=True, key=lambda x: x[0])
            print("Possible Diagnoses (sorted by likelihood):")
            for weight, conclusion in possible_diagnoses:
                print(f"{conclusion} (Confidence: {weight * 100}%)")
        else:
            # If no rule matches, fall back to the default rule
            default_rule = self.rules[-1]
            print(f"Diagnosis: {default_rule[2]} (Confidence: {default_rule[1] * 100}%)")


# Example usage
system = RuleBasedSystem('rules1.txt')
system.input_symptoms()
system.diagnose()
