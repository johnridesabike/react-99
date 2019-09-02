import React from "react";
import ReactDOM from "react-dom";
import { BLINK, CENTER, BASEFONT, FONT } from "../index";

const SuperCoolHeader = () =>
  <CENTER>
    <BLINK>
      <FONT color="red" size="7">Get up and slam!</FONT>
    </BLINK>
  </CENTER>;

const MindBlowingEffect = () =>
  <BASEFONT color="green" size={5} face="comic sans ms">
    <CENTER>
      <marquee>
        And welcome to the <FONT size="+1">Jam.</FONT>
      </marquee>
    </CENTER>
  </BASEFONT>;
/* 
ReactDOM.render(<SuperCoolHeader />, document.getElementById("reactJSExample1"))
ReactDOM.render(<MindBlowingEffect />, document.getElementById("reactJSExample2"))
 */