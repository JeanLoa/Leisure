from google.colab import files
files.upload()
---------------------------------------------
!mkdir -p ~/.kaggle
!cp kaggle.json ~/.kaggle/
!chmod 600 ~/.kaggle/kaggle.json
---------------------------------------------
!pip install kaggle
---------------------------------------------
!kaggle competitions download -c titanic
!unzip titanic.zip
---------------------------------------------
import pandas as pd
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.preprocessing import OneHotEncoder, StandardScaler
from xgboost import XGBClassifier
from sklearn.compose import ColumnTransformer
from sklearn.metrics import accuracy_score
from sklearn.pipeline import Pipeline

# 1. Carga, preprocesamiento y feature engineering de datos

df = pd.read_csv('train.csv')

df["CabinDeck"] = df["Cabin"].fillna("Unknown").astype(str).str[0]
df["FamilySize"] = df["SibSp"] + df["Parch"] + 1
df["IsAlone"] = df["FamilySize"].apply(lambda x: 1 if x == 1 else 0)

categorical_cols = ['Pclass', 'Sex', 'CabinDeck', 'Embarked', 'IsAlone']
numerical_cols = ['Age', 'SibSp', 'Parch', 'Fare', 'FamilySize']

df[categorical_cols] = df[categorical_cols].fillna('Unknown')
df[numerical_cols] = df[numerical_cols].fillna(df[numerical_cols].mean())

X = df.drop('Survived', axis=1)
y = df['Survived']

X_train, X_test, y_train, y_test = train_test_split(
    X, 
    y,
    test_size=0.2,
    random_state=42,
    stratify=y
    )

# 2. Transformer de columnas

preprocess = ColumnTransformer(
    transformers=[
        ('cat', OneHotEncoder(handle_unknown='ignore'), categorical_cols),
        ('num', StandardScaler(), numerical_cols)
    ]
)

# 3. Pipeline

pipeline = Pipeline([
    ('preprocess', preprocess),
    ('model', XGBClassifier())
])

# 4. Grid

grid_params = {
    'model__max_depth': [3, 4, 5, 7],
    'model__learning_rate': [0.1, 0.01, 0.05],
    'model__n_estimators': [100, 200, 500],
    'model__min_child_weight': [3, 5, 7],
    'model__colsample_bytree': [0.5, 0.7]
}

grid_search = GridSearchCV(
    pipeline,
    param_grid=grid_params,
    scoring='accuracy',
    n_jobs=-1,
    cv=5,
    verbose=True
)

# 5. Entrenamiento

grid_search.fit(X_train, y_train)

best_model = grid_search.best_estimator_

y_pred = best_model.predict(X_test)

accuracy_train = accuracy_score(y_train, best_model.predict(X_train))
accuracy_test = accuracy_score(y_test, y_pred)

# 6. Resultados

print(f"TRAIN: {accuracy_train}")
print(f"TEST: {accuracy_test}")
