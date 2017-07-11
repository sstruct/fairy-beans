# visualizing decision tree
import numpy as np
from sklearn.datasets import load_iris
from sklearn import tree

# import dataset
iris = load_iris()

# split dataset
test_idx = [0, 50, 100]
# print all data
# for i in range(len(iris.target)):
#     print "example %d: label %s, features %s" % (i, iris.target[i], iris.data[i])
# training data
train_target = np.delete(iris.target, test_idx)
train_data = np.delete(iris.data, test_idx, axis=0)

# testing data
test_target = iris.target[test_idx]
test_data = iris.data[test_idx]

# train classifier
clf = tree.DecisionTreeClassifier()
clf.fit(train_data, train_target)

print test_target

from sklearn.externals.six import StringIO
import pydotplus
# pridict label for new flower
dot_data = StringIO()
tree.export_graphviz(clf,
                     out_file=dot_data,
                     feature_names=iris.feature_names,
                     class_names=iris.target_names,
                     filled=True, rounded=True,
                     impurity=False)

graph = pydotplus.graph_from_dot_data(dot_data.getvalue())
graph.write_pdf("iris.pdf")

print iris.feature_names, iris.target_names
