# Server Charms Workshop

This is the code and documentation of a workshop we did for the first time at the CFC25 Conference in Hamburg.
In our workshop, we create a tiny, portable microcontroller setups (Server Charms), which create their own Wi-Fi network. This network
shows up in the Wi-Fi list of nearby devices, inviting curious people to connect with their devices. Once they do, a captive portal opens, leadingto a small webpage – displaying our server charm manifesto. We are running the microcontrollers on recycled vape batteries which means that the code is optimzed for small power source.

## Repository Structure

```
├── sketch
│   ├── sketch.ino
│   └── html.h
│   └── index.html
├── README.md
└── documentation-zine-[date].pdf
```

`documentation-zine-[date].pdf` contains a work-in-progress documentation of how to build a server charm, our server charm manifsto as well as a small glossary. It also links to this repository. We will update the zine in the future.
`sketch.ino` contains the code that is flashed onto the microcontroller to open an access point, host a website and to publish it in a captive portal.
`html.h` contains the html code of the website. It is imported into `sketch.ino`.
`index.html` is an example template for a website. This file is not actually necessary to upload the sketch. You can use it to edit the website but the code need to be copied to `html.h` to be included.

## The Code

Generally, it opens an access point that redirects traffic to a local server at `192.168.4.1` when phones check captive portal URLs. Since this code is optimized for an ESP32 running on small recycled vape batteries, it allows only 4 clients and is set to use low transmission power to prevent high energy spikes.

### Changing the SSID

To change the name of the WiFi, change the `*ssid` value to a name of your choice.

### Adding Password Protection

```cpp
if (WiFi.softAP(ssid, nullptr, 6, false, maxClients))
```

To:

```cpp
if (WiFi.softAP(ssid, "your_password", 6, false, maxClients))
```

### Increasing WiFi Range

Change the transmission power from `WIFI_POWER_19_5dBm` to lower values to save power:

```cpp
WiFi.setTxPower(WIFI_POWER_11dBm);  // Maximum range
```

Available power levels: `WIFI_POWER_19_5dBm`, `WIFI_POWER_18_5dBm`, `WIFI_POWER_17dBm`, `WIFI_POWER_15dBm`, `WIFI_POWER_13dBm`, `WIFI_POWER_11dBm`, `WIFI_POWER_8_5dBm`, `WIFI_POWER_7dBm`, `WIFI_POWER_5dBm`, `WIFI_POWER_2dBm`

## Allowing More Clients

Change the `maxClients` value e.g. to

```cpp
const int maxClients = 5;  // Allow up to 5 clients
```

Note that more clients require more energy! So far, the ESP can handle around 5 clients.

### Switching Website content

#### look_around

Simple click-through html site. The `index.html` page is just to have an page that you can view in the browser. You can edit the website here and afterwards copy the content to `html.h` before flashing.

```cpp
const char index_html[] PROGMEM = R"rawliteral(
// Your HTML content here
)rawliteral";
```

#### guestbook

Guestbook template with no styling. Here you can play around with the html Strings in the `sketch.ino`.
