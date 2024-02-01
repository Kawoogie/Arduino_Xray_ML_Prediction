<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!-- -->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Kawoogie/Arduino_Xray_ML_Prediction">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Arduino Xray Mean Energy ML Prediction</h3>

  <p align="center">
    This code takes three input values from an X-ray detector and uses machine learning to predict the mean energy value of the X-ray.
    <br />
    <a href="https://github.com/Kawoogie/Arduino_Xray_ML_Prediction"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Kawoogie/Arduino_Xray_ML_Prediction">View Demo</a>
    ·
    <a href="https://github.com/Kawoogie/Arduino_Xray_ML_Prediction/issues">Report Bug</a>
    ·
    <a href="https://github.com/Kawoogie/Arduino_Xray_ML_Prediction/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>    
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This project uses the serial monitor to get inputs from the user of the measured values from an Xray meter to make a prediction about the mean energy of the Xray machine.

This code uses the output of the tinyML gen package for Python to make machine learning predictions on an Arduino Nano 33 BLE Sense Lite.

Here is the tinyML gen repository:
https://github.com/eloquentarduino/tinymlgen

The above repository uses Python to generate C code for running a machine learning model on a microprocessor. This is what generated the RandomForest.h model
included in this repository.

<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- GETTING STARTED -->
## Getting Started

This code is written for the Arduino Nano 33 BLE Sense Lite.

You will also need the two files in the code section of this repository as well as the Arduino IDE.

### Prerequisites


The header file containing the machine learning model needs to be downloaded and imported into your sketch.
   ```sh
   #include "RandomForest.h" // Load the header file with the model
   ```

### Installation

The machine learning model is initialized from the included header file with this command:
   ```sh
   // Initialize the model
   Eloquent::ML::Port::RandomForestRegressor mlmodel;
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

The prediction is being done with this command:
   ```sh
   mlmodel.predict(inputData)
   ```
To input data for the model to make a prediction on, it must be entered through the serial monitor in this format:
   ```sh
   [float, float, float]
   ```
With the float values ranging between 0.0 and 1.0.

The output of the machine learning model is an estimation of the mean energy of the X-ray in a float value. 


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/Kawoogie/Arduino_Xray_ML_Prediction/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact
Project Link: [https://github.com/Kawoogie/Arduino_Xray_ML_Prediction](https://github.com/Kawoogie/Arduino_Xray_ML_Prediction)

<p align="right">(<a href="#readme-top">back to top</a>)</p>






<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Kawoogie/Arduino_Xray_ML_Prediction.svg?style=for-the-badge
[contributors-url]: https://github.com/Kawoogie/Arduino_Xray_ML_Prediction/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Kawoogie/Arduino_Xray_ML_Prediction.svg?style=for-the-badge
[forks-url]: https://github.com/Kawoogie/Arduino_Xray_ML_Prediction/network/members
[stars-shield]: https://img.shields.io/github/stars/Kawoogie/Arduino_Xray_ML_Prediction.svg?style=for-the-badge
[stars-url]: https://github.com/Kawoogie/Arduino_Xray_ML_Prediction/stargazers
[issues-shield]: https://img.shields.io/github/issues/Kawoogie/Arduino_Xray_ML_Prediction.svg?style=for-the-badge
[issues-url]: https://github.com/Kawoogie/Arduino_Xray_ML_Prediction/issues
[license-shield]: https://img.shields.io/github/license/Kawoogie/Arduino_Xray_ML_Prediction.svg?style=for-the-badge
[license-url]: https://github.com/Kawoogie/Arduino_Xray_ML_Prediction/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/lee-sikstrom-a6472a113
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com
