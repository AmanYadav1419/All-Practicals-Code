import nltk
from nltk.tokenize import word_tokenize
from nltk.tag import pos_tag
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer,WordNetLemmatizer
from sklearn.feature_extraction.text import TfidfVectorizer

#RUN BELOW COMMANDS ONLY ONCE AS WE NEED TO DOWNLOAD THESE LIBS. AFTER THAT COMMENT OR REMOVE THEM
#nltk.download('punkt')
#nltk.download('averaged_perceptron_tagger')
#nltk.download('stopwords')
#nltk.download('wordnet')

#APART FROM THESE USE THE COMMAND " pip install numpy scikit-learn " in terminal to download numpy and scikit-learn

document = "Once upon a time in a small village nestled among green hills, there lived a young shepherd named Peter. He spent his days tending to his flock of sheep, wandering through meadows and singing songs."

# TOKENIZATION
print("# Tokenization\n")
tokens = word_tokenize(document)
print(tokens)

# POS TAGGING
print("\n# POS Tagging\n")
pos_tags = pos_tag(tokens)
print(pos_tags)

# STOP WORDS REMOVAL
print("\n# Stop Words Removal\n")
stop_words = set(stopwords.words("english"))
filtered_tokens = [token for token in tokens if token.lower() not in stop_words]
print(filtered_tokens)

# STEMMING
print("\n# Stemming\n")
stemmer = PorterStemmer()
stemmed_tokens = [stemmer.stem(token) for token in filtered_tokens]
print(stemmed_tokens)

# LEMMATIZATION
print("\n# Lemmatization \n")
lemmatizer = WordNetLemmatizer()
lemmatized_tokens = [lemmatizer.lemmatize(token) for token in filtered_tokens]
print(lemmatized_tokens)

# TF-IDF REPRESENTATION
print("\n# TF-IDF Representation\n")
tfidf_vectorizer = TfidfVectorizer()
tfidf_matrix = tfidf_vectorizer.fit_transform([document])
print(tfidf_matrix.toarray())
print("\n# FEATURED NAMES \n")
print(tfidf_vectorizer.get_feature_names_out())

