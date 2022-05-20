import pandas as pd

pdObj = pd.read_json('json_data.json')
pdObj.to_csv('data_file.csv', index=False)