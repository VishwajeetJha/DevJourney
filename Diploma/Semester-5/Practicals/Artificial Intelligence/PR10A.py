import pandas as pd

def identify_missing_values(csv_file):
    df = pd.read_csv(csv_file)
    missing_values = df.isnull().sum()
    return missing_values

if __name__ == "__main__":
    csv_file_path = "/content/data.csv"  # Replace with actual file path
    missing_values = identify_missing_values(csv_file_path)
    
    print("Missing Values:")
    print(missing_values)
