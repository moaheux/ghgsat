
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>

// #define TEST
using namespace std;
struct s_captureSettings
{
    string mode;
    int frequency;
    int fps;
    int exposure;
    float gain_r;
    float gain_g;
    float gain_b;
};
struct s_coordinates
{
    double latitude;
    double longitude;
    double altitude;
};
struct s_capture
{
    string title;
    string id;
    string name;
    string timestamp;

    struct s_captureSettings captureSettings;
    struct s_coordinates coordinates;
};

int Search_in_File(fstream& fp, string str, string *arg);

int main(void)
{
    int res = 0;

#ifdef TEST
    string filename;
    string label;
    string arg ;
    cout << "Enter Name of file to test" << endl;
    cin >> filename;
    filename.insert(0,"files/");
    filename.append(".sexp");
    fstream  fp(filename);
    if (!fp.is_open())
    {
        cout << "File couldn't be open" << endl;
        return 0;
    }
    cout << "Enter string to find" << endl;
    cin >> label <<endl;

    res = Search_in_File(fp, label, &arg);
    if(0 == res)
        cout << "string not found" << endl;
    else
        cout << "output " << arg;
    return res;
#else
    fstream  fp("files/example.sexp");
    string c_capture = "Capture";
    string c_id = "id";
    string c_name = "name";
    string c_timestamp = "timestamp";
    string c_mode = "mode";
    string c_frequency = "frequency";
    string c_fps = "fps";
    string c_exposure = "exposure";
    string c_gain_r = "gain_r";
    string c_gain_g = "gain_g";
    string c_gain_b = "gain_b";
    string c_latitude = "latitude";
    string c_longitude = "longitude";
    string c_altitude = "altitude";

    string arg ;
    struct s_capture capture;

    if (!fp.is_open())
    {
        cout << "File couldn't be open" << endl;
        return 0;
    }
    res = Search_in_File(fp, c_capture, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.title = arg;
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_id, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.id = arg;
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_name, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.name = arg;
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_timestamp, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.timestamp = arg;
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_mode, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.captureSettings.mode = arg;
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_frequency, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.captureSettings.frequency = stoi(arg);
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_fps, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.captureSettings.fps = stoi(arg);
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_exposure, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.captureSettings.exposure = stoi(arg);
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_gain_r, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.captureSettings.gain_r = stof(arg);
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_gain_g, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.captureSettings.gain_g = stof(arg);
    fp.clear();
    fp.seekg(0, fp.beg);
    
    res = Search_in_File(fp, c_gain_b, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.captureSettings.gain_b = stof(arg);
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_latitude, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.coordinates.latitude = stod(arg);
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_longitude, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.coordinates.longitude = stod(arg);
    fp.clear();
    fp.seekg(0, fp.beg);

    res = Search_in_File(fp, c_altitude, &arg);
    if(0 == res)
    {
        cout << "string not found" << endl;
        return res;
    }
    capture.coordinates.altitude = stod(arg);
    fp.clear();
    fp.seekg(0, fp.beg);

    // Close the file if still open.

    cout << "title (string)        " << capture.title << endl;
    cout << "Capture" << endl;
    cout <<"  id        (string)   " << capture.id << endl;
    cout <<"  name      (string)   " << capture.name << endl;
    cout <<"  timestamp (string)   " << capture.timestamp << endl;
    cout <<"  CaptureSettings" << endl;
    cout <<"    mode      (string) " << capture.captureSettings.mode << endl;
    cout <<"    frequency (int)    " << capture.captureSettings.frequency<< endl;
    cout <<"    fps       (int)    " << capture.captureSettings.fps<< endl;
    cout <<"    exposure  (int)    " << capture.captureSettings.exposure<< endl;
    cout <<"    gain_r    (float)  " << capture.captureSettings.gain_r<< endl;
    cout <<"    gain_g    (float)  " << capture.captureSettings.gain_g<< endl;
    cout <<"    gain_b    (float)  " << setprecision( 7 ) << capture.captureSettings.gain_b<< endl;
    cout <<"  Coordinates" <<endl;
    cout <<"    latitude  (double) " << fixed << setprecision( 7 ) << capture.coordinates.latitude<< endl;
    cout <<"    longitude (double) " << fixed << setprecision( 6 ) << capture.coordinates.longitude<< endl;
    cout <<"    altitude  (double) " << setprecision( 0 ) << capture.coordinates.altitude<< endl;

    if (fp.is_open())
    {
        fp.close();
    }
    return res;
#endif
}

int Search_in_File(fstream& fp, string str, string *arg)
{
    int res = 0;
    string str1;
    size_t posLabel;
    bool found = false;
    char * p;
    getline (fp,str1);

    while ( fp ) 
    {  // Continue if the line was sucessfully read.

        posLabel = str1.find(str);
        if (posLabel!=std::string::npos)
        {
            char * cstr = new char [str1.length()+1];
            found = true;

            std::strcpy (cstr, str1.c_str());

            // cstr now contains a c-string copy of str

            p = std::strtok (cstr," ()");
            while (p!=0)
            {
                if(!strcmp(p,str.c_str()))
                {
                    p = std::strtok(NULL," ()");
                    break;
                }
                p = std::strtok(NULL," ()");
            }
            break;
        }
        getline (fp,str1);
    }
    if (found)
    {
        *arg=string(p);
        res = 1;
    }
    else
        res = 0;
    return res;
}