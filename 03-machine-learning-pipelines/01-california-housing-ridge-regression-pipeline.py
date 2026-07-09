from sklearn.datasets import fetch_california_housing
from sklearn.model_selection import train_test_split
from sklearn.model_selection import GridSearchCV
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import PolynomialFeatures
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import Ridge

data = fetch_california_housing(as_frame=True)
df = data.frame
X = df.drop(columns='MedHouseVal')
y = df['MedHouseVal']

X_train, X_temp, y_train, y_temp = train_test_split(X, y, test_size=0.40, random_state=42)

X_val, X_test, y_val, y_test = train_test_split(X_temp, y_temp, test_size=0.50, random_state=42)

pipeline = Pipeline([
    ('poly', PolynomialFeatures(include_bias=False)),
    ('scaler', StandardScaler()),
    ('model', Ridge())
])

param_grid = {
    "poly__degree": [1, 2, 3],
    "poly__interaction_only": [False],
    "model__alpha": [1e-3, 1e-2, 1e-1, 1, 10, 100, 1000]
}

grid = GridSearchCV(pipeline, param_grid, cv=7, scoring="r2", verbose=2, n_jobs=-1)
grid.fit(X_train, y_train)

print(f"Best parameters: {grid.best_params_}")

model = grid.best_estimator_

print("TRAIN:", model.score(X_train, y_train))
print("VAL  :", model.score(X_val, y_val))
print("TEST :", model.score(X_test, y_test))
