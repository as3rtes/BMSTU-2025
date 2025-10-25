#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
//Variant 6
double parseNumber(const char* str) {
    double result = 0.0;
    double fraction = 0.0;
    double divisor = 1.0;
    bool afterDot = false;

    while (*str != '\0' && *str != ';') {
        if (*str == '.') {
            afterDot = true;
        }

        else if (*str >= '0' && *str <= '9') {
            int digit = *str - '0';

            if (!afterDot) {
                result = result * 10 + digit;
            }
            else {
                divisor *= 10.0;
                fraction += digit / divisor;
            }
        }
        str++;
    }

    return result + fraction;
}

int main() {
    vector<string> navData = {
        "LAT:55.7522;LON:37.6156;ALT:180.5;SPD:7.4",
        "LAT:55.7519;LON:37.6161;ALT:182.3;SPD:7.8",
        "LAT:55.7515;LON:37.6169;ALT:183.1;SPD:8.1"
    };

    vector<double> latitudes;
    vector<double> longitudes;
    vector<double> altitudes;
    vector<double> speeds;

    for (const auto& line : navData) {


        const char* p = line.c_str();

        while (*p != '\0') {
            if (*p == 'L' && *(p+ 1) == 'A' && *(p + 2) == 'T' && *(p +3) == ':') {

                p += 4;
                latitudes.push_back(parseNumber(p));
            }
            else if (*p == 'L' && *(p+ 1) == 'O' && *(p + 2)== 'N' && *(p+ 3) == ':')  {
                p += 4;
                    longitudes.push_back(parseNumber(p));
            }

            else if (*p == 'A' && *(p+1) == 'L' && *(p + 2) == 'T' && *(p+3)== ':') {
                p += 4;

                altitudes.push_back(parseNumber(p));
            }
            else if (*p == 'S' && *(p +1) == 'P' && *(p + 2)== 'D' && *(p + 3)  == ':') {
                p += 4;
                speeds.push_back(parseNumber(p));
            }

            else {
                p++;
            }

        }


    }
    double vr_Altitudes = 0.0;
    double sumAltitude = 0.0;
    for (double alt : altitudes) {

        sumAltitude += alt;
    }
    double averageAltitude = sumAltitude / altitudes.size();

    double maxSpeed = speeds[0];
    for (double speed : speeds) {
        if (speed > maxSpeed) {
            maxSpeed = speed;

        }

    }


    double totalDiff = 0.0;
    int count = 0;

    for (size_t i = 1; i < latitudes.size(); i++) {
        double latDiff = fabs(latitudes[i] - latitudes[i - 1]);
        double lonDiff = fabs(longitudes[i] - longitudes[i - 1]);

        totalDiff += (latDiff + lonDiff) / 2.0;

        count++;
    }

    double averageShift = totalDiff / count;

    for (size_t i = 1; i < speeds.size(); i++) {
        double speedDiff = fabs(speeds[i] - speeds[i - 1]);
        if (speedDiff > 0.5) {
            cout << "Uneven movement is detected " << i << " and " << i + 1 << endl;
        }

    }

    cout << "Average altitudde: " << averageAltitude << " m" << endl;
    cout << "Max speed: " << maxSpeed << " m/s" << endl;
    cout << "Average lat/ lon shift: " << averageShift;

    return 0;
}
