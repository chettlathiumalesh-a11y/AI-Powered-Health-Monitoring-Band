import numpy as np
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
import joblib

data = pd.read_csv("data_samples.csv")
X = data[["heartRate", "spo2"]]
y = data["health_status"]

model = RandomForestClassifier()
model.fit(X, y)

joblib.dump(model, "health_predict_model.pkl")
print("Model saved")
