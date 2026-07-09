from google.colab import files
files.upload()
---------------------------------------------
!mkdir ~/.kaggle
!cp kaggle.json ~/.kaggle/
!chmod 600 ~/.kaggle/kaggle.json
---------------------------------------------
!kaggle datasets download -d redwankarimsony/heart-disease-data
---------------------------------------------
!unzip heart-disease-data.zip
---------------------------------------------
import pandas as pd
df = pd.read_csv("heart_disease_uci.csv")
print(df.columns.tolist())
---------------------------------------------
from sklearn.preprocessing import OneHotEncoder, StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.pipeline import Pipeline
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.compose import ColumnTransformer
from sklearn.metrics import roc_auc_score, accuracy_score

import numpy as np
import pandas as pd

df.replace("?", np.nan, inplace=True)
df.fillna(0, inplace=True)

categorical_features = ['sex', 'cp', 'fbs', 'restecg', 'exang', 'slope', 'ca', 'thal']
numerical_features = ['age', 'trestbps', 'chol', 'thalch', 'oldpeak']

for col in categorical_features:
    df[col] = df[col].astype(str)

preprocessor = ColumnTransformer([
    ('encoder', OneHotEncoder(handle_unknown='ignore'), categorical_features),
    ('scaler', StandardScaler(with_mean=False), numerical_features)
])

param_grid = {
    'model__n_estimators': [300, 500, 800],
    'model__max_depth': [5, 10, 20],
    'model__max_features': ['sqrt'],
    'model__min_samples_split': [2, 5, 10],
    'model__min_samples_leaf': [1, 2, 4]
}

X = df.drop('num', axis=1)
y = df['num'].astype(int)  # IMPORTANTE

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

pipeline = Pipeline([
    ('preprocessor', preprocessor),
    ('model', RandomForestClassifier())
])

grid_search = GridSearchCV(
    pipeline,
    param_grid,
    cv=5,
    scoring='roc_auc',
    n_jobs=-1
)

grid_search.fit(X_train, y_train)

model = grid_search.best_estimator_
y_pred = model.predict(X_test)
y_prob = model.predict_proba(X_test)

print("BEST PARAMS:", grid_search.best_params_)
print("TEST ACCURACY:", accuracy_score(y_test, y_pred))
print("TEST ROC-AUC:", roc_auc_score(y_test, y_prob, multi_class='ovr'))
print("TRAIN SCORE:", model.score(X_train, y_train))
---------------------------------------------
import shap
import numpy as np

X_test_transformed = model.named_steps["preprocessor"].transform(X_test)

ohe = model.named_steps["preprocessor"].named_transformers_["encoder"]
ohe_features = ohe.get_feature_names_out(categorical_features)
all_features = list(ohe_features) + numerical_features

explainer = shap.Explainer(model.named_steps["model"], X_test_transformed)

shap_values = explainer(X_test_transformed)

print("shap values shape:", shap_values.values.shape)
print("X_test_transformed shape:", X_test_transformed.shape)

shap.summary_plot(shap_values.values, X_test_transformed, feature_names=all_features)
