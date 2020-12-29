require('dotenv').config();
const { LCD, Board } = require('johnny-five');
const got = require('got');

const RS = process.env.RS | 12;
const EN = process.env.EN | 11;
const DB4 = process.env.DB4 | 5;
const DB5 = process.env.DB5 | 4;
const DB6 = process.env.DB7 | 3;
const DB7 = process.env.DB8 | 2;
const PORT = process.env.PORT | 3000;
const API_KEY = process.env.API_KEY;
const CITY = process.env.CITY;
const COUNTRY = process.env.COUNTRY;
const API_URL = 'http://api.openweathermap.org/data/2.5/weather';
const REFRESH = 1000 * 60 * 60; // 1000 millisec * 60 sec * 60 min


const board = new Board();
let lcd;

async function getWeather() {
  const { body } = await got(API_URL, {
    searchParams: {
      q: `${CITY},${COUNTRY}`,
      units: 'metric',
      lang: 'it',
      APPID: API_KEY,
    },
  });
  board.log('API', body);
  writeWeather(JSON.parse(body));
  return body;
}

function writeWeather(weather) {
  const temp = weather.main.temp;
  const humidity = weather.main.humidity;
  const windSpeed = weather.wind.speed;
  const windDegree = weather.wind.deg;
  lcd.cursor(0, 0).print(`T:${temp}C h:${humidity}% `).print(':smile:');
  lcd
    .cursor(1, 0)
    .print(`w:${windSpeed}m/s `)
    .print(`${windDegree}`)
    .print(':arrowne:');
}

function onReady() {
  lcd = new LCD({
    pins: [RS, EN, DB4, DB5, DB6, DB7],
    rows: 2,
    cols: 16,
  });

  lcd.useChar('arrowne');
  lcd.useChar('smile');

  lcd.clear();
  getWeather();

  board.loop(REFRESH, () => {
    getWeather();
  });
}

board.on('ready', onReady);
