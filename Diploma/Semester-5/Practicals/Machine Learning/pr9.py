import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt

company_ticker = 'AAPL'

start_date = '2024-09-01'
end_date = '2024-09-14'

stock_data = yf.download(company_ticker, start=start_date, end=end_date)

stock_data.reset_index(inplace=True)

fig, ax = plt.subplots(6, 1, figsize=(10, 12), sharex=True)

# Plot Open price
ax[0].plot(stock_data['Date'], stock_data['Open'], label='Open', color='blue')
ax[0].set_ylabel('Open Price')
ax[0].legend()

# Plot High price
ax[1].plot(stock_data['Date'], stock_data['High'], label='High', color='green')
ax[1].set_ylabel('High Price')
ax[1].legend()

# Plot Low price
ax[2].plot(stock_data['Date'], stock_data['Low'], label='Low', color='red')
ax[2].set_ylabel('Low Price')
ax[2].legend()

# Plot Close price
ax[3].plot(stock_data['Date'], stock_data['Close'], label='Close', color='orange')
ax[3].set_ylabel('Close Price')
ax[3].legend()

# Plot Adjusted Close price
ax[4].plot(stock_data['Date'], stock_data['Adj Close'], label='Adjusted Close', color='purple')
ax[4].set_ylabel('Adj Close Price')
ax[4].legend()

# Plot Volume
ax[5].bar(stock_data['Date'], stock_data['Volume'], label='Volume', color='gray')
ax[5].set_ylabel('Volume')
ax[5].legend()

#formaating
plt.xticks(rotation=45)
plt.xlabel('Date')
plt.tight_layout()

plt.show()
