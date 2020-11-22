#include <iostream>
#include <cpp_httplib/httplib.h>
using namespace std;
using namespace httplib;
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
void gen_response(const Request& req, Response& res) {
	Client cli("http://worldtimeapi.org");
	auto resd = cli.Get("/api/timezone/Europe/Simferopol");
	Client cliw("api.openweathermap.org");
	auto wsi = cliw.Get("/data/2.5/onecall?lat=44.957191&lon=34.11079&exclude=minutely&lang=ru&units=metric&appid=4b574cac6c8640cdd2713e78e60469e2");
	if (resd && wsi) {
		// Проверяем статус ответа, т.к. может быть 404 и другие
		if (resd->status == 200 && wsi->status == 200) {
			//Проблем нет
			string wordtime = resd->body;
			json j = json::parse(wordtime);
			int unixtimenow = j["unixtime"]; // МСК
			string wordwea = wsi->body;
			json h = json::parse(wordwea);//Массив погоды Hourly ,temp, icon, description, dt
			json cache;
			// если максимальный юникс прогноза + 1 час >= нынешнего проверка по кешу иначе создание кеша + новый прогноз
			//достать кеш
			ifstream src("cache.json");
			if (src)
			{
				src >> cache;
			}
			
				double tempNOW;
				string descriptionNOW;
				string iconNOW;
				if (empty(cache)) {
					cache["hourly"][47]["dt"] = 0;
				}
			if (int(cache["hourly"][47]["dt"]) + 3600 >= unixtimenow) {
				for (int i = 0; i < 48; i++)
				{
					if (abs(unixtimenow - cache["hourly"][i]["dt"]) <= 3600) {
						tempNOW = cache["hourly"][i]["temp"];
						descriptionNOW = cache["hourly"][i]["weather"][0]["description"];
						iconNOW = cache["hourly"][i]["weather"][0]["icon"];

						break;
					}
				}

			}
			else {
				tempNOW = h["hourly"][0]["temp"];
				descriptionNOW = h["hourly"][0]["weather"][0]["description"];
				iconNOW = h["hourly"][0]["weather"][0]["icon"];
				ofstream srco("cache.json");
				srco << h;
			}
			////к этому моменту в любом исходе необходимы данные иконки описания и температуры  tempNOW descriptionNOW iconNOW
			ifstream file("nowvisual.html"); // Файловая переменная
			string str;                 // Буфер. Тут будет текст файла
			getline(file, str, '\0');// str html страница изменить значения temp*2
			//// Конструкция замены html данными
			string word1 = "{hourly[i].weather[0].description}";
			string word2 = "{hourly[i].weather[0].icon}";
			string word3 = "{hourly[i].temp}";
			int num1 = size(word1);
			int num2 = size(word2);
			int num3 = size(word3);
			str.replace(str.find(word1), num1, descriptionNOW);
			str.replace(str.find(word3), num3, to_string(int(round(tempNOW))));
			str.replace(str.find(word3), num3, to_string(int(round(tempNOW))));
			str.replace(str.find(word2), num2, iconNOW);
			//// fin html
		/*	cout << str;*/// console check info
			res.set_content(str, "text/html");// Вывод
		}
		else {
			cout << "Status code: " << resd->status << endl;
		}
	}
	else {
		auto err = resd.error();
		cout << "Error code: " << err << endl;
	}
}

void gen_responseraw(const Request& req, Response& res) {
	Client cli("http://worldtimeapi.org");
	auto resd = cli.Get("/api/timezone/Europe/Simferopol");
	Client cliw("api.openweathermap.org");
	auto wsi = cliw.Get("/data/2.5/onecall?lat=44.957191&lon=34.11079&exclude=minutely&lang=ru&units=metric&appid=4b574cac6c8640cdd2713e78e60469e2");
	if (resd && wsi) {
		// Проверяем статус ответа, т.к. может быть 404 и другие
		if (resd->status == 200 && wsi->status == 200) {
			//Проблем нет
			string wordtime = resd->body;
			json j = json::parse(wordtime);
			int unixtimenow = j["unixtime"]; // МСК
			string wordwea = wsi->body;
			json h = json::parse(wordwea);//Массив погоды Hourly ,temp, icon, description, dt
			json cache;
			// если максимальный юникс прогноза + 1 час >= нынешнего проверка по кешу иначе создание кеша + новый прогноз
			//достать кеш
			//Получение кеша
			ifstream src("cache.json");
			
			if (src)
			{
				src >> cache;
			}

			double tempNOW = 0;
			string descriptionNOW;
			string iconNOW;
			if (empty(cache)) {
				cache["hourly"][47]["dt"] = 0;
			}
			if (int(cache["hourly"][47]["dt"]) + 3600 >= unixtimenow) {
				// Есть прогноз
				for (int i = 0; i < 48; i++)
				{
					if (abs(unixtimenow - cache["hourly"][i]["dt"]) <= 3600) {
						tempNOW = cache["hourly"][i]["temp"];
						descriptionNOW = cache["hourly"][i]["weather"][0]["description"];
						iconNOW = cache["hourly"][i]["weather"][0]["icon"];

						break;
					}
				}
			}
			else {
				// Прогноза нет
				tempNOW = h["hourly"][0]["temp"];
				descriptionNOW = h["hourly"][0]["weather"][0]["description"];
				iconNOW = h["hourly"][0]["weather"][0]["icon"];
				// ..Новый кеш
				ofstream srco("cache.json");
				srco << h;
			}
			json str;
			str["temp"] = to_string(int(round(tempNOW)));
			str["description"] = descriptionNOW;
			/*cout << str;*/
			res.set_content(str.dump(), "text/json");
		}
		else {
		cout << "Status code: " << resd->status << endl;
		}
	}
	else {
	auto err = resd.error();
	cout << "Error code: " << err << endl;
	}
}
int main() {
	Server svr;                
	svr.Get("/", gen_response);    // Виджет
	svr.Get("/raw", gen_responseraw);  // Данные для клиента
	std::cout << "Start server... OK\n";
	svr.listen("localhost", 3000);
}