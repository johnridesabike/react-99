%raw
{|var blinkCss =
  "@keyframes react_99_epic_blink {"
  + "0% {visibility: hidden;}"
  + "50% {visibility: hidden;}"
  + "100% {visibility: visible;}}";
var style = document.createElement('style');
document.head.appendChild(style);
style.type = 'text/css';
style.appendChild(document.createTextNode(blinkCss))|};
[@react.component]
let make = (~children) => {
  <div
    style={ReactDOMRe.Style.make(
      ~animation="2s linear infinite react_99_epic_blink",
      (),
    )}>
    children
  </div>;
};