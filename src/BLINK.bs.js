// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as React from "react";

var blinkCss =
  "@keyframes react_99_epic_blink {"
  + "0% {visibility: hidden;}"
  + "50% {visibility: hidden;}"
  + "100% {visibility: visible;}}";
var style = document.createElement('style');
document.head.appendChild(style);
style.type = 'text/css';
style.appendChild(document.createTextNode(blinkCss))
;

function BLINK(Props) {
  var children = Props.children;
  return React.createElement("div", {
              style: {
                animation: "2s linear infinite react_99_epic_blink"
              }
            }, children);
}

var make = BLINK;

export {
  make ,
  
}
/*  Not a pure module */
