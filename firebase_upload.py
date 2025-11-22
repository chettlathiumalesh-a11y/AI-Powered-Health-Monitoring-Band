import pandas as pd
import firebase_admin
from firebase_admin import credentials, firestore

cred = credentials.Certificate("serviceAccountKey.json")
firebase_admin.initialize_app(cred)
db = firestore.client()

df = pd.read_csv("data_samples.csv")

for _, row in df.iterrows():
    db.collection("HealthBand").add({
        "heartRate": row["heartRate"],
        "spo2": row["spo2"],
        "prediction": row["health_status"]
    })

print("Data uploaded to Firebase")
