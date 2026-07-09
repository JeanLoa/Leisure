import seaborn as sns

df = sns.load_dataset('iris')

sns.pairplot(df, vars=['sepal_lenght', 'sepal_width', 'petal_lenght', 'petal_width'], hue='species', kind='scatter', diag_kind='kde')
