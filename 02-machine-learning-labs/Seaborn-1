import seaborn as sns

df = sns.load_dataset('tips')

sns.pairplot(df, vars=['total_bill', 'tip', 'size'], hue='time', kind='scatter', diag_kind='kde')
