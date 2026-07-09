import seaborn as sns

df = sns.load_dataset('diamonds')

sns.pairplot(df, vars=['carat', 'price', 'depth', 'table'], hue='cut', palette='Set2', diag_kind='hist')
