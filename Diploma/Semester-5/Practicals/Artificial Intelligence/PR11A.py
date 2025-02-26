import numpy as np

def identify_noisy_value(age_data):
    mean_age = np.mean(age_data)
    std_age = np.std(age_data)

    # Identify noisy values based on z-score threshold (e.g., 1)
    z_scores = [(age - mean_age) / std_age for age in age_data]
    noisy_values = [age_data[i] for i, z_score in enumerate(z_scores) if abs(z_score) > 1]

    return noisy_values

if __name__ == "__main__":
    age_data = [25, 30, 22, 28, 80, 26, 24, 23, 75, 1000]  # Sample dataset with outliers
    noisy_values = identify_noisy_value(age_data)
    
    print("Noisy Values:")
    print(noisy_values)
