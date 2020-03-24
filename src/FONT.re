[@react.component]
let make = (~color=?, ~face=?, ~size=?, ~children: React.element) => {
  <span
    style={BASEFONT.Font.makeStyle(
      BASEFONT.useContext(),
      ~color,
      ~face,
      ~size,
    )}>
    children
  </span>;
};
