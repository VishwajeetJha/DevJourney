package com.mp.weatherapp;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import org.json.JSONArray;
import org.json.JSONObject;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import android.util.Log;
import android.os.AsyncTask;

public class MainActivity extends AppCompatActivity {
    EditText cityName;
    Button search;
    TextView show;

    // Member variables to store city and state names
    private String city;
    private String state;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        cityName = findViewById(R.id.cityName);
        search = findViewById(R.id.search);
        show = findViewById(R.id.weather);

        search.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String cityInput = cityName.getText().toString().trim();
                if (cityInput.isEmpty()) {
                    Toast.makeText(MainActivity.this, "Enter City", Toast.LENGTH_SHORT).show();
                    return;
                }

                city = cityInput; // Store the city name
                // Fetch geo data for the entered city
                String geoUrl = "https://api.openweathermap.org/geo/1.0/direct?q=" + city + "&limit=2&appid=4a1f73f87cd51e44b856c134ba0b2552";
                new FetchGeoData().execute(geoUrl);
            }
        });
    }

    // AsyncTask to fetch geo data
    private class FetchGeoData extends AsyncTask<String, Void, double[]> {
        @Override
        protected double[] doInBackground(String... urls) {
            String urlString = urls[0];
            String response = null;

            try {
                response = getHttpResponse(urlString);
                Log.d("GeoDataResponse", response);

                JSONArray jsonArray = new JSONArray(response);

                if (jsonArray.length() > 0) {
                    JSONObject jsonObject = jsonArray.getJSONObject(0);
                    state = jsonObject.optString("state", ""); // Extract state name (if available)
                    double lat = jsonObject.getDouble("lat");
                    double lon = jsonObject.getDouble("lon");
                    return new double[]{lat, lon}; // Returning lat and lon as an array
                }
            } catch (Exception e) {
                e.printStackTrace();
            }

            return null;
        }

        @Override
        protected void onPostExecute(double[] result) {
            if (result != null) {
                // If lat and lon are available, fetch weather data
                String weatherUrl = "https://api.openweathermap.org/data/2.5/weather?lat=" + result[0] + "&lon=" + result[1] + "&appid=4a1f73f87cd51e44b856c134ba0b2552&units=metric";
                new FetchWeatherData().execute(weatherUrl);
            } else {
                show.setText("Cannot find location data");
            }
        }

        private String getHttpResponse(String urlString) {
            StringBuilder result = new StringBuilder();
            try {
                URL url = new URL(urlString);
                HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
                urlConnection.connect();

                InputStream inputStream = urlConnection.getInputStream();
                BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));

                String line;
                while ((line = reader.readLine()) != null) {
                    result.append(line).append("\n");
                }
                return result.toString();
            } catch (Exception e) {
                e.printStackTrace();
                return null;
            }
        }
    }

    // AsyncTask to fetch weather data
    private class FetchWeatherData extends AsyncTask<String, Void, String> {
        @Override
        protected String doInBackground(String... urls) {
            String urlString = urls[0];
            String response = null;

            try {
                response = getHttpResponse(urlString);
                return response; // Return the full JSON response
            } catch (Exception e) {
                e.printStackTrace();
            }

            return null;
        }

        @Override
        protected void onPostExecute(String result) {
            if (result != null) {
                try {
                    Log.d("WeatherResponse", result);
                    JSONObject jsonObject = new JSONObject(result);
                    JSONObject main = jsonObject.getJSONObject("main");
                    JSONArray weatherArray = jsonObject.getJSONArray("weather");
                    JSONObject weather = weatherArray.getJSONObject(0);

                    // Use stored city and state names
                    String weatherInfo = city + ", " + state + "\n\n" + // Include city and state
                            "Current Weather: " + weather.getString("main") + " (" + weather.getString("description") + ")\n\n" +
                            "Temperature: " + main.getString("temp") + "°C\n" +
                            "Feels Like: " + main.getString("feels_like") + "°C\n" +
                            "Max Temperature: " + main.getString("temp_max") + "°C\n" +
                            "Min Temperature: " + main.getString("temp_min") + "°C\n" +
                            "Pressure: " + main.getString("pressure") + " hPa\n" +
                            "Humidity: " + main.getString("humidity") + "%";

                    show.setText(weatherInfo);
                } catch (Exception e) {
                    e.printStackTrace();
                    show.setText("Error parsing weather data");
                }
            } else {
                show.setText("Cannot find weather data");
            }
        }

        private String getHttpResponse(String urlString) {
            StringBuilder result = new StringBuilder();
            try {
                URL url = new URL(urlString);
                HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
                urlConnection.connect();

                InputStream inputStream = urlConnection.getInputStream();
                BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));

                String line;
                while ((line = reader.readLine()) != null) {
                    result.append(line).append("\n");
                }
                return result.toString();
            } catch (Exception e) {
                e.printStackTrace();
                return null;
            }
        }
    }
}