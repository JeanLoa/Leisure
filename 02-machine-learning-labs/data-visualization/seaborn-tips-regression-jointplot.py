import seaborn as sns
import matplotlib.pyplot as plt

df = sns.load_dataset("tips")

sns.jointplot(data=df, x="total_bill", y="tip", kind="reg")
plt.show()
