import nltk
import random
from nltk.corpus import movie_reviews
from sklearn.model_selection import KFold
from sklearn.naive_bayes import MultinomialNB
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.pipeline import make_pipeline
from sklearn import metrics

def extract_features(words):
    return dict([(word, True) for word in words])

def text_classification(use_sklearn=False, cross_validate=False):
    nltk.download('movie_reviews', quiet=True)
    documents = [(list(movie_reviews.words(fileid)), category)
                 for category in movie_reviews.categories()
                 for fileid in movie_reviews.fileids(category)]
    random.shuffle(documents)
    
    sentences = [' '.join(words) for words, _ in documents]
    labels = [category for _, category in documents]
    
    if cross_validate:  # Cross-validation using sklearn
        kf = KFold(n_splits=5, shuffle=True, random_state=42)
        accuracy_scores = []
        for train_idx, test_idx in kf.split(sentences):
            X_train, X_test = [sentences[i] for i in train_idx], [sentences[i] for i in test_idx]
            y_train, y_test = [labels[i] for i in train_idx], [labels[i] for i in test_idx]
            model = make_pipeline(CountVectorizer(), MultinomialNB())
            model.fit(X_train, y_train)
            accuracy_scores.append(metrics.accuracy_score(y_test, model.predict(X_test)))
        print("Cross-Validation Mean Accuracy:", sum(accuracy_scores) / len(accuracy_scores))
    else:  # Naive Bayes classification using NLTK
        featuresets = [(extract_features(words), category) for words, category in documents]
        train_set, test_set = featuresets[:1500], featuresets[1500:]
        classifier = nltk.NaiveBayesClassifier.train(train_set)
        print("NLTK Naive Bayes Accuracy:", nltk.classify.accuracy(classifier, test_set))

    user_input = input("Enter a review to classify: ")
    if use_sklearn:
        model = make_pipeline(CountVectorizer(), MultinomialNB())
        model.fit(sentences, labels)
        print("Sentiment:", model.predict([user_input])[0])
    else:
        features = extract_features(user_input.split())
        print("Sentiment:", classifier.classify(features))

if __name__ == "__main__":
    text_classification(use_sklearn=True, cross_validate=True)
