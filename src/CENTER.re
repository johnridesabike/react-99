[@react.component]
let make = (~children) => {
  <div style={ReactDOMRe.Style.make(~textAlign="center", ())}>
    children
  </div>;
};