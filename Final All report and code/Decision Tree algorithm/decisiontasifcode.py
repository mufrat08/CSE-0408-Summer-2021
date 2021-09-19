import pandas as pd
import numpy as np

df = pd.read_csv("datadt.csv")

df

X = df.iloc[:,:-1]

X

y = df.iloc[:,3]

y

from sklearn.preprocessing import LabelEncoder

LabelEncoder_X = LabelEncoder()

X = X.apply(LabelEncoder().fit_transform)

X

from sklearn.tree import DecisionTreeClassifier

regressor = DecisionTreeClassifier()

regressor.fit(X.iloc[:,1:4], y)

X_in = np.array([1,0,])

y_pred = regressor.predict([X_in])

y_pred
