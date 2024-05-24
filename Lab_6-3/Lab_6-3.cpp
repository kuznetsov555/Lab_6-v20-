#include <iostream>;
using namespace std;

// Абстрактный класс для шкалы температур
class TemperatureScale {
public:
    virtual double convertToKelvin(double temperature) const = 0;
};

// Класс шкалы измерения температур по Цельсию
class CelsiusScale : public TemperatureScale {
public:
    double convertToKelvin(double temperature) const override {
        return temperature + 273.15;
    }
};

// Класс шкалы измерения температур по Фаренгейту
class FahrenheitScale : public TemperatureScale {
public:
    double convertToKelvin(double temperature) const override {
        return (temperature - 32) * 5 / 9 + 273.15;
    }
};

// Адаптеры для перевода температур между разными шкалами
class CelsiusToKelvinAdapter {
public:
    static double convert(double temperature) {
        return temperature + 273.15;
    }
};

class FahrenheitToCelsiusAdapter {
public:
    static double convert(double temperature) {
        return (temperature - 32) * 5 / 9;
    }
};

class CelsiusToFahrenheitAdapter {
public:
    static double convert(double temperature) {
        return temperature * 9 / 5 + 32;
    }
};

class FahrenheitToKelvinAdapter {
public:
    static double convert(double temperature) {
        return (temperature - 32) * 5 / 9 + 273.15;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    double celsiusTemperature = 25.0;

    // Пример использования адаптеров
    double kelvinTemperatureFromCelsius = CelsiusToKelvinAdapter::convert(celsiusTemperature);
    double fahrenheitTemperatureFromCelsius = CelsiusToFahrenheitAdapter::convert(celsiusTemperature);

    double fahrenheitTemperature = 77.0;
    double kelvinTemperatureFromFahrenheit = FahrenheitToKelvinAdapter::convert(fahrenheitTemperature);
    double celsiusTemperatureFromFahrenheit = FahrenheitToCelsiusAdapter::convert(fahrenheitTemperature);

    cout << "25 градусов Цельсия в Кельвины: " << kelvinTemperatureFromCelsius << endl;
    cout << "25 градусов Цельсия в Фаренгейты: " << fahrenheitTemperatureFromCelsius << endl;
    cout << "77 градусов Фаренгейта в Кельвины: " << kelvinTemperatureFromFahrenheit << endl;
    cout << "77 градусов Фаренгейта в Цельсии: " << celsiusTemperatureFromFahrenheit << endl;

    return 0;
}