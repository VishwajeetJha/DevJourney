import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt

# Define the company ticker (e.g., AAPL for Apple, MSFT for Microsoft)
company_ticker = 'AAPL'


start_date = '2024-09-01'
end_date = '2024-09-14'

# Download stock data using yfinance
stock = yf.download(company_ticker, start=start_date, end=end_date)

stock.reset_index(inplace=True)

plt.figure(figsize=(10, 6))
plt.plot(stock['Date'], stock['Open'], label='Opening Price', marker='o')
plt.plot(stock['Date'], stock['Close'], label='Closing Price', marker='o')

plt.title(f'{company_ticker} Stock Prices from {start_date} to {end_date}')
plt.xlabel('Date')
plt.ylabel('Price')
plt.xticks(rotation=45)
plt.legend()

plt.tight_layout()
plt.show()
