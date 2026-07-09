import pandas as pd
import matplotlib.pyplot as plt
from sklearn import model_selection
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.multiclass import OneVsRestClassifier
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import accuracy_score, classification_report
from sklearn.model_selection import GridSearchCV

iris = load_iris()

X = iris.data
y = iris.target

feature_names = iris.feature_names
target_names = iris.target_names

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

pipeline = Pipeline([
    ('scaler', StandardScaler()),
    ('model', OneVsRestClassifier(
    DecisionTreeClassifier(max_depth=4, random_state=42)
))
])

param_grid = {
    'model__estimator__max_depth': [3,
                                     4,
                                     5,
                                     6,
                                     7,
                                     8,
                                     9,
                                     10],
}

grid_search = GridSearchCV(pipeline, param_grid, cv=5, scoring='accuracy')

grid_search.fit(X_train, y_train)

model = grid_search.best_estimator_

y_pred = model.predict(X_test)

print("Accuracy:", accuracy_score(y_test, y_pred))
print("\nReporte de Clasificación:\n", classification_report(y_test, y_pred))
---------------------------------------------
plt.figure(figsize=(15, 10))
plot_tree(model.estimators_[0] if hasattr(model, "estimators_") else model,
          feature_names=feature_names,
          class_names=target_names,
          filled=True,
          rounded=True)
plt.show()
