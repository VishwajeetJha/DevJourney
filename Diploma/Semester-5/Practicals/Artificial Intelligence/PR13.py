import nltk
import re
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.stem import PorterStemmer, WordNetLemmatizer

def clean_text(passage):
    # Remove special characters and convert to lowercase
    passage = re.sub(r'[^a-zA-Z0-9\s]', '', passage)
    return passage.lower()

def extract_stop_words_and_process(file_path, use_stemming=True):
    # Ensure necessary NLTK resources are downloaded
    nltk.download('stopwords', quiet=True)
    nltk.download('punkt', quiet=True)
    nltk.download('wordnet', quiet=True)

    stop_words = set(stopwords.words('english'))

    with open(file_path, 'r') as file:
        passage = file.read()

    # Clean the text
    cleaned_passage = clean_text(passage)

    words = word_tokenize(cleaned_passage)

    # Choose stemming or lemmatization
    if use_stemming:
        stemmer = PorterStemmer()
        processed_words = [stemmer.stem(word) for word in words]
    else:
        lemmatizer = WordNetLemmatizer()
        processed_words = [lemmatizer.lemmatize(word) for word in words]

    found_stop_words = [word for word in processed_words if word in stop_words]

    return found_stop_words

if __name__ == "__main__":
    file_path = "/content/stop.txt"

    # Change use_stemming to False for lemmatization
    stop_words_in_passage = extract_stop_words_and_process(file_path, use_stemming=True)

    print("Stop Words Found:")
    print(stop_words_in_passage)
