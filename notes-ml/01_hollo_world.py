# 01 Simple classify
from sklearn import tree

# training data
# input
features = [[140, 1], [130, 0], [139, 0], [170, 0]]
# output
labels = ["apple", "apple", "orange", "orange"]

# superized learning
clf = tree.DecisionTreeClassifier()
clf = clf.fit(features, labels)
print clf.predict([[150, 0], [130, 1]])
