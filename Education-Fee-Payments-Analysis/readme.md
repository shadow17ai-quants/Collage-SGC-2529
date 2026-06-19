*Education Fee Payments Analysis

An exploratory data analysis (EDA) pipeline analyzing 721 unique student fee payment records (2023–2024) for P.N. Rao Education institutions.

##Dataset & Metrics 

The pipeline processes PNRao_Education_Fee_Payments.csv across 7 schema fields: 

1. PaymentID 
2. StudentID 
3. Amount 
4. PaymentDate
5. Semester 
6. Year
7. Method

Key Data Insights Completeness: 

1. 0 missing values across all 721 entries.
2. Average Payment: ₹95,26,898.94
3. Transaction Range: ₹70,85,575.30 to ₹1,17,98,457.35

Pipeline Steps:

1. Integrity Check: Audited schema data types and verified zero null fields.
2. Type Conversion: Converted PaymentDate text strings to robust datetime64 objects for time-series analysis.
3. Statistical Profiling:  Generated distribution metrics (mean, min, max, standard deviation) for institutional cash flows converted to Indian Rupees (INR).

Dependencies:

1. Engine: Python 3.8+
2. Libraries: Pandas, Matplotlib
3. Enviorment: Jupyter Notebook

