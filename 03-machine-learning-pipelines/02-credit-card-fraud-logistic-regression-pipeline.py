from google.colab import files
files.upload()
---------------------------------------------
!mkdir -p ~/.kaggle
!mv kaggle.json ~/.kaggle/
!chmod 600 ~/.kaggle/kaggle.json
---------------------------------------------
!pip install kaggle
---------------------------------------------
!kaggle datasets download -d mlg-ulb/creditcardfraud
---------------------------------------------
import zipfile

with zipfile.ZipFile("creditcardfraud.zip", "r") as z:
    z.extractall()
---------------------------------------------
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.model_selection import GridSearchCV
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix, roc_auc_score
from sklearn.pipeline import Pipeline

df = pd.read_csv("creditcard.csv")

X = df.drop("Class", axis=1)
y = df["Class"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4, random_state=42, stratify=y)
X_test, X_val, y_test, y_val = train_test_split(X_test, y_test, test_size=0.5, random_state=42, stratify=y_test)

pipeline = Pipeline([
    ('scaler', StandardScaler()),
    ('classifier', LogisticRegression())
])

param_grid = {
    'classifier__C': [0.001, 0.01, 0.1, 1, 10, 100, 1000]
    }

grid_search = GridSearchCV(pipeline, param_grid, cv=5, scoring='accuracy')
grid_search.fit(X_train, y_train)

best_model = grid_search.best_estimator_

print("TRAIN: ", grid_search.score(X_train, y_train))
print("TEST: ", grid_search.score(X_test, y_test))
print("VAL: ", grid_search.score(X_val, y_val))
---------------------------------------------
from sklearn.metrics import classification_report, roc_auc_score, f1_score

y_pred = best_model.predict(X_test)
y_proba = best_model.predict_proba(X_test)[:, 1]

print(f"Classification Report: {classification_report(y_test, y_pred)}")
print(f"ROC AUC Score: {roc_auc_score(y_test, y_proba)}")
print(f"F1 Score: {f1_score(y_test, y_pred)}")
