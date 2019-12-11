[@react.component]
let make = (~color=?, ~face=?, ~size=?, ~children:React.element) => {
  <span style={BASEFONT.makeFontStyle(~color, ~face, ~size, BASEFONT.useContext())}>
    children
  </span>;
};