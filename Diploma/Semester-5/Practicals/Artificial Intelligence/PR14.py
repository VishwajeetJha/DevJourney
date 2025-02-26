import nltk
import random
from nltk.corpus import movie_reviews
from sklearn.naive_bayes import MultinomialNB
from sklearn.tree import DecisionTreeClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import KFold
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.pipeline import make_pipeline
from sklearn.metrics import accuracy_score

def create_feature_sets(documents):
    return [' '.join(words) for words, category in documents], [category for words, category in documents]

def text_classification():
    nltk.download('movie_reviews', quiet=True)

    # Load movie reviews dataset
    documents = [(list(movie_reviews.words(fileid)), category)
                 for category in movie_reviews.categories()
                 for fileid in movie_reviews.fileids(category)]

    random.shuffle(documents)

    # Prepare the dataset
    sentences, labels = create_feature_sets(documents)

    # Define classifiers
    classifiers = {
        "Naive Bayes": MultinomialNB(),
        "Decision Tree": DecisionTreeClassifier(),
        "Logistic Regression": LogisticRegression(max_iter=200)
    }

    # Prepare cross-validation
    kf = KFold(n_splits=5, shuffle=True, random_state=42)

    # Iterate through classifiers
    for classifier_name, classifier in classifiers.items():
        accuracy_scores = []

        for train_index, test_index in kf.split(sentences):
            X_train, X_test = [sentences[i] for i in train_index], [sentences[i] for i in test_index]
            y_train, y_test = [labels[i] for i in train_index], [labels[i] for i in test_index]

            # Create a pipeline with CountVectorizer
            model = make_pipeline(CountVectorizer(), classifier)
            model.fit(X_train, y_train)

            # Predict and evaluate
            y_pred = model.predict(X_test)
            accuracy = accuracy_score(y_test, y_pred)
            accuracy_scores.append(accuracy)

        print(f"{classifier_name} Cross-Validation Accuracies: {accuracy_scores}")
        print(f"{classifier_name} Mean Accuracy: {sum(accuracy_scores) / len(accuracy_scores)}")

    # Input for single review classification using the best classifier (example: Naive Bayes)
    user_input = input("Enter a review to classify using Naive Bayes: ")
    naive_bayes_model = make_pipeline(CountVectorizer(), MultinomialNB())
    naive_bayes_model.fit(sentences, labels)
    sentiment = naive_bayes_model.predict([user_input])
    print("Sentiment (Naive Bayes):", sentiment[0])

if __name__ == "__main__":
    text_classification()
