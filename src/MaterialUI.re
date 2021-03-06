type jsUnsafe;

external toJsUnsafe : 'a => jsUnsafe = "%identity";

let unwrapValue =
    (
      r: [<
        | `Int(int)
        | `IntArray(array(int))
        | `String(string)
        | `StringArray(array(string))
        | `Float(float)
        | `FloatArray(array(float))
      ],
    ) =>
  switch (r) {
  | `String(s) => toJsUnsafe(s)
  | `Int(i) => toJsUnsafe(i)
  | `StringArray(a) => toJsUnsafe(a)
  | `IntArray(a) => toJsUnsafe(a)
  | `Float(a) => toJsUnsafe(a)
  | `FloatArray(a) => toJsUnsafe(a)
  };

let unwrap_bool = (b: option(bool)) =>
  switch (b) {
  | Some(value) => Js.Nullable.return(Js.Boolean.to_js_boolean(value))
  | None => Js.Nullable.undefined
  };

let option_map = (fn, option) =>
  switch (option) {
  | Some(value) => Some(fn(value))
  | None => None
  };

module AppBar = {
  [@bs.module "material-ui/AppBar"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~position: option(string)=?,
        ~color: option(string)=?,
        ~classes: option(Js.t({..}))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~className: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "position": from_opt(position),
            "color": from_opt(color),
            "classes": from_opt(classes),
            "style": from_opt(style),
            "className": from_opt(className),
          }
        ),
      children,
    );
};

module Avatar = {
  [@bs.module "material-ui/Avatar"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~alt: option(string)=?,
        ~className: option(string)=?,
        ~classes: option('t)=?,
        ~childrenClassName: option(string)=?,
        ~component: option(string)=?,
        ~imgProps: option(Js.t({..}))=?,
        ~sizes: option(string)=?,
        ~src: option(string)=?,
        ~srcSet: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "alt": from_opt(alt),
            "childrenClassName": from_opt(childrenClassName),
            "className": from_opt(className),
            "classes": from_opt(classes),
            "component": from_opt(component),
            "imgProps": from_opt(imgProps),
            "sizes": from_opt(sizes),
            "src": from_opt(src),
            "srcSet": from_opt(srcSet),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Badge = {
  [@bs.module "material-ui/Badge"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~badgeContent: array(ReasonReact.reactElement),
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {"badgeContent": badgeContent, "style": from_opt(style)}
        ),
      children,
    );
};

module ButtonBase = {
  [@bs.module "material-ui/ButtonBase"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~style: option(ReactDOMRe.style)=?,
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        ~component: option(string)=?,
        ~className: option(string)=?,
        ~centerRipple=?,
        ~disableRipple=?,
        ~focusRipple=?,
        ~disabled=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "focusRipple": unwrap_bool(focusRipple),
            "centerRipple": unwrap_bool(centerRipple),
            "disableRipple": unwrap_bool(disableRipple),
            "disabled": unwrap_bool(disabled),
            "onClick": from_opt(onClick),
            "component": from_opt(component),
            "className": from_opt(className),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Button = {
  module Color = {
    type t =
      | Default
      | Inherit
      | Primary
      | Contrast
      | Accent;
    let to_string =
      fun
      | Default => "default"
      | Inherit => "inherit"
      | Primary => "primary"
      | Contrast => "contrast"
      | Accent => "accent";
  };
  [@bs.module "material-ui/Button"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~color: option(Color.t)=?,
        ~component: option(string)=?,
        ~dense=?,
        ~disabled=?,
        ~disableFocusRipple=?,
        ~disableRipple=?,
        ~fab=?,
        ~href: option(string)=?,
        ~raised=?,
        ~_type: option(string)=?,
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "color": from_opt(option_map(Color.to_string, color)),
            "component": from_opt(component),
            "dense": unwrap_bool(dense),
            "disabled": unwrap_bool(disabled),
            "disableFocusRipple": unwrap_bool(disableFocusRipple),
            "disableRipple": unwrap_bool(disableRipple),
            "fab": unwrap_bool(fab),
            "href": from_opt(href),
            "raised": unwrap_bool(raised),
            "type": from_opt(_type),
            "style": from_opt(style),
            "onClick": from_opt(onClick),
          }
        ),
      children,
    );
};

module CardActions = {
  [@bs.module "material-ui/Card"]
  external reactClass : ReasonReact.reactClass = "CardActions";
  let make =
      (~disableActionSpacing=?, ~style: option(ReactDOMRe.style)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "disableActionSpacing": unwrap_bool(disableActionSpacing),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module CardContent = {
  [@bs.module "material-ui/Card"]
  external reactClass : ReasonReact.reactClass = "CardContent";
  let make = (~style: option(ReactDOMRe.style)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=Js.Nullable.({"style": from_opt(style)}),
      children,
    );
};

module CardHeader = {
  [@bs.module "material-ui/Card"]
  external reactClass : ReasonReact.reactClass = "CardHeader";
  let make =
      (
        ~action: option(ReasonReact.reactElement)=?,
        ~avatar: option(ReasonReact.reactElement)=?,
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~title: option(ReasonReact.reactElement)=?,
        ~subheader: option(ReasonReact.reactElement)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "action": from_opt(action),
            "avatar": from_opt(avatar),
            "classes": from_opt(classes),
            "className": from_opt(className),
            "style": from_opt(style),
            "subheader": from_opt(subheader),
            "title": from_opt(title),
          }
        ),
      children,
    );
};

module CardMedia = {
  [@bs.module "material-ui/Card"]
  external reactClass : ReasonReact.reactClass = "CardMedia";
  let make =
      (
        ~style: option(ReactDOMRe.style)=?,
        ~image: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.({"style": from_opt(style), "image": from_opt(image)}),
      children,
    );
};

module Card = {
  [@bs.module "material-ui/Card"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~raised=?,
        ~style: option(ReactDOMRe.style)=?,
        ~className: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "raised": unwrap_bool(raised),
            "style": from_opt(style),
            "className": from_opt(className),
          }
        ),
      children,
    );
};

module Checkbox = {
  [@bs.module "material-ui/Checkbox"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      /* technically a union bool|string but why are you passing a string to `checked`? */
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~checked: option(bool)=?,
        ~checkedClassName: option(string)=?,
        ~checkedIcon: option(ReasonReact.reactElement)=?,
        ~disableRipple: option(bool)=?,
        ~disabled: option(bool)=?,
        ~disabledClassName: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~indeterminate: option(bool)=?,
        ~indeterminateIcon: option(ReasonReact.reactElement)=?,
        /* TODO inputProps */
        /* TODO inputRef */
        ~name: option(string)=?,
        ~onChange: option((ReactEventRe.Selection.t, Js.boolean) => unit)=?,
        ~value: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "checked": unwrap_bool(checked),
            "checkedClassName": from_opt(checkedClassName),
            "checkedIcon": from_opt(checkedIcon),
            "disableRipple": unwrap_bool(disableRipple),
            "disabled": unwrap_bool(disabled),
            "disabledClassName": from_opt(disabledClassName),
            "icon": from_opt(icon),
            "indeterminate": unwrap_bool(indeterminate),
            "indeterminateIcon": from_opt(indeterminateIcon),
            "name": from_opt(name),
            "onChange": from_opt(onChange),
            "value": from_opt(value),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Chip = {
  [@bs.module "material-ui/Chip"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~avatar: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~classes: option(Js.t({..}))=?,
        ~deleteIcon: option(ReasonReact.reactElement)=?,
        ~label: option(string),
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        ~onKeyDown: option(ReactEventRe.Keyboard.t)=?,
        ~onRequestDelete: option(ReactEventRe.Synthetic.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~tabIndex: option([ | `String(string) | `Int(int)])=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "avatar": from_opt(avatar),
            "className": from_opt(className),
            "classes": from_opt(classes),
            "deleteIcon": from_opt(deleteIcon),
            "label": from_opt(label),
            "onClick": from_opt(onClick),
            "onKeyDown": from_opt(onKeyDown),
            "onRequestDelete": from_opt(onRequestDelete),
            "style": from_opt(style),
            "tabIndex": from_opt(option_map(unwrapValue, tabIndex)),
          }
        ),
      children,
    );
};

module CircularProgress = {
  [@bs.module "material-ui/Progress"]
  external reactClass : ReasonReact.reactClass = "CircularProgress";
  let make =
      (
        ~style: option(ReactDOMRe.style)=?,
        ~className: option(string)=?,
        ~classes: option(Js.t({..}))=?,
        ~color: option(string)=?,
        ~value: option(int)=?,
        ~valueBuffer: option(int)=?,
        ~mode: option(string)=?,
        ~size: option(int)=?,
        ~max: option(int)=?,
        ~min: option(int)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "style": from_opt(style),
            "mode": from_opt(mode),
            "classes": from_opt(classes),
            "color": from_opt(color),
            "valueBuffer": from_opt(valueBuffer),
            "value": from_opt(value),
            "size": from_opt(size),
            "max": from_opt(max),
            "min": from_opt(min),
            "className": from_opt(className),
          }
        ),
      children,
    );
};

module Collapse = {
  [@bs.module "material-ui/transitions/Collapse"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~expanded: option(bool)=?,
        ~transitionDuration: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "in": unwrap_bool(expanded),
            "transitionDuration": from_opt(transitionDuration),
          }
        ),
      children,
    );
};

module DialogActions = {
  [@bs.module "material-ui/Dialog"]
  external reactClass : ReasonReact.reactClass = "DialogActions";
  type dialogActionsClasses = {
    root: option(string),
    action: option(string),
    button: option(string),
  };
  let make = (~classes: option(dialogActionsClasses)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=Js.Nullable.({"classes": from_opt(classes)}),
      children,
    );
};

module DialogContentText = {
  [@bs.module "material-ui/Dialog"]
  external reactClass : ReasonReact.reactClass = "DialogContentText";
  let make = (~style: option(ReactDOMRe.style)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=Js.Nullable.({"style": from_opt(style)}),
      children,
    );
};

module DialogContent = {
  [@bs.module "material-ui/Dialog"]
  external reactClass : ReasonReact.reactClass = "DialogContent";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {"classes": from_opt(classes), "style": from_opt(style)}
        ),
      children,
    );
};

module DialogTitle = {
  [@bs.module "material-ui/Dialog"]
  external reactClass : ReasonReact.reactClass = "DialogTitle";
  type dialogTitleClasses = {root: option(string)};
  let make =
      (
        ~classes: option(dialogTitleClasses)=?,
        ~disableTypography: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "disableTypography": from_opt(disableTypography),
          }
        ),
      children,
    );
};

module Dialog = {
  [@bs.module "material-ui/Dialog"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~enterTransitionDuration: option(int)=?,
        ~leaveTransitionDuration: option(int)=?,
        ~fullScreen: option(bool)=?,
        ~ignoreBackdropClick: option(bool)=?,
        ~ignoreEscapeKeyUp: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~onBackdropClick: option(unit => unit)=?,
        ~onEnter: option(unit => unit)=?,
        ~onEntered: option(unit => unit)=?,
        ~onEntering: option(unit => unit)=?,
        ~onEscapeKeyUp: option(unit => unit)=?,
        ~onExit: option(unit => unit)=?,
        ~onExited: option(unit => unit)=?,
        ~onExiting: option(unit => unit)=?,
        ~onClose: option(unit => unit)=?,
        ~openDialog: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "style": from_opt(style),
            "classes": from_opt(classes),
            "fullScreen": from_opt(fullScreen),
            "leaveTransitionDuration": from_opt(leaveTransitionDuration),
            "enterTransitionDuration": from_opt(enterTransitionDuration),
            "ignoreEscapeKeyUp": from_opt(ignoreEscapeKeyUp),
            "ignoreBackdropClick": from_opt(ignoreBackdropClick),
            "onBackdropClick": from_opt(onBackdropClick),
            "onEnter": from_opt(onEnter),
            "onEntered": from_opt(onEntered),
            "onEntering": from_opt(onEntering),
            "onEscapeKeyUp": from_opt(onEscapeKeyUp),
            "onExit": from_opt(onExit),
            "onExited": from_opt(onExited),
            "onExiting": from_opt(onExiting),
            "onClose": from_opt(onClose),
            "open": from_opt(openDialog),
          }
        ),
      children,
    );
};

module Divider = {
  [@bs.module "material-ui/Divider"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~inset: option(bool)=?,
        ~light: option(bool)=?,
        ~absolute: option(bool)=?,
        ~className: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "light": unwrap_bool(light),
            "inset": unwrap_bool(inset),
            "absolute": unwrap_bool(absolute),
            "className": from_opt(className),
          }
        ),
      children,
    );
};

module Drawer = {
  module Anchor = {
    type t =
      | Left
      | Top
      | Right
      | Bottom;
    let to_string =
      fun
      | Left => "left"
      | Top => "top"
      | Right => "right"
      | Bottom => "bottom";
  };
  module Type = {
    type t =
      | Permanent
      | Persistent
      | Temporary;
    let to_string =
      fun
      | Permanent => "permanent"
      | Persistent => "persistent"
      | Temporary => "temporary";
  };
  [@bs.module "material-ui/Drawer"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~anchor: option(Anchor.t)=?,
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~elevation: option(int)=?,
        ~transitionDuration: option(Js.t({..}))=?,
        ~modalProps: option(Js.t({..}))=?,
        ~onClose: option(unit => unit)=?,
        ~_open: option(bool)=?,
        ~slideProps: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "anchor": from_opt(option_map(Anchor.to_string, anchor)),
            "classes": from_opt(classes),
            "className": from_opt(className),
            "elevation": from_opt(elevation),
            "transitionDuration": from_opt(transitionDuration),
            "ModalProps": from_opt(modalProps),
            "onClose": from_opt(onClose),
            "open": unwrap_bool(_open),
            "SlideProps": from_opt(slideProps),
            "type": from_opt(option_map(Type.to_string, _type)),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Margin = {
  type t =
    | None
    | Dense
    | Normal;
  let to_string =
    fun
    | None => "none"
    | Dense => "dense"
    | Normal => "normal";
};

module FormControl = {
  [@bs.module "material-ui/Form"]
  external reactClass : ReasonReact.reactClass = "FormControl";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
        ~onFocus: option(ReactEventRe.Focus.t => unit)=?,
        ~required: option(bool)=?,
        ~margin: option(Margin.t)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "disabled": unwrap_bool(disabled),
            "error": unwrap_bool(error),
            "fullWidth": unwrap_bool(fullWidth),
            "onBlur": from_opt(onBlur),
            "onFocus": from_opt(onFocus),
            "required": unwrap_bool(required),
            "margin": from_opt(option_map(Margin.to_string, margin)),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module FormControlLabel = {
  [@bs.module "material-ui/Form"]
  external reactClass : ReasonReact.reactClass = "FormControlLabel";
  let make =
      /* technically a union bool|string but why are you passing a string to `checked`? */
      (
        ~checked: option(bool)=?,
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~control: option(ReasonReact.reactElement)=?,
        ~disabled: option(bool)=?,
        /* TODO: is actually a  function */
        ~inputRef=?,
        /* TODO: is actually a Node */
        ~label: option(string)=?,
        ~name: option(string)=?,
        ~onChange: option(ReactEventRe.Selection.t => unit)=?,
        ~value: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "checked": from_opt(checked),
            "classes": from_opt(classes),
            "className": from_opt(className),
            "control": from_opt(control),
            "disabled": unwrap_bool(disabled),
            "inputRef": from_opt(inputRef),
            "label": from_opt(label),
            "name": from_opt(name),
            "onChange": from_opt(onChange),
            "value": from_opt(value),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module FormGroup = {
  [@bs.module "material-ui/Form"]
  external reactClass : ReasonReact.reactClass = "FormGroup";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~row: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "row": unwrap_bool(row),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module FormHelperText = {
  [@bs.module "material-ui/Form"]
  external reactClass : ReasonReact.reactClass = "FormHelperText";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~margin: option(Margin.t)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "disabled": unwrap_bool(disabled),
            "error": unwrap_bool(error),
            "margin": from_opt(option_map(Margin.to_string, margin)),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module FormLabel = {
  [@bs.module "material-ui/Form"]
  external reactClass : ReasonReact.reactClass = "FormLabel";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~focused: option(bool)=?,
        ~required: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "disabled": unwrap_bool(disabled),
            "error": unwrap_bool(error),
            "focused": unwrap_bool(focused),
            "required": unwrap_bool(required),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Grid = {
  [@bs.module "material-ui/Grid"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~align: option(string)=?,
        ~component: option(string)=?,
        ~direction: option(string)=?,
        ~wrap: option(string)=?,
        ~justify: option(string)=?,
        ~xl: option(int)=?,
        ~lg: option(int)=?,
        ~md: option(int)=?,
        ~sm: option(int)=?,
        ~xs: option(int)=?,
        ~spacing: option(int)=?,
        ~container: option(bool)=?,
        ~item: option(bool)=?,
        ~className: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "container": unwrap_bool(container),
            "item": unwrap_bool(item),
            "style": from_opt(style),
            "className": from_opt(className),
            "align": from_opt(align),
            "component": from_opt(component),
            "direction": from_opt(direction),
            "wrap": from_opt(wrap),
            "justify": from_opt(justify),
            "xl": from_opt(xl),
            "lg": from_opt(lg),
            "md": from_opt(md),
            "sm": from_opt(sm),
            "xs": from_opt(xs),
            "spacing": from_opt(spacing),
            "wrp": from_opt(wrap),
          }
        ),
      children,
    );
};

module Icon = {
  [@bs.module "material-ui/Icon"]
  external reactClass : ReasonReact.reactClass = "default";
  module Color = {
    type t =
      | Default
      | Inherit
      | Primary
      | Contrast
      | Accent;
    let to_string =
      fun
      | Default => "default"
      | Inherit => "inherit"
      | Primary => "primary"
      | Contrast => "contrast"
      | Accent => "accent";
  };
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~color: option(Color.t)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "color": from_opt(option_map(Color.to_string, color)),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module IconButton = {
  [@bs.module "material-ui/IconButton"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~color: option(Icon.Color.t)=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "color": from_opt(option_map(Icon.Color.to_string, color)),
            "disableRipple": unwrap_bool(disableRipple),
            "disabled": unwrap_bool(disabled),
            "style": from_opt(style),
            "onClick": from_opt(onClick),
          }
        ),
      children,
    );
};

module InputLabel = {
  [@bs.module "material-ui/Input"]
  external reactClass : ReasonReact.reactClass = "InputLabel";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~disableAnimation: option(bool)=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~_FormControlClasses: option(Js.t({..}))=?,
        ~focused: option(bool)=?,
        ~htmlFor: option(string)=?,
        ~margin: option(Margin.t)=?,
        ~required: option(bool)=?,
        ~shrink: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "disableAnimation": unwrap_bool(disableAnimation),
            "disabled": unwrap_bool(disabled),
            "error": unwrap_bool(error),
            "FormControlClasses": from_opt(_FormControlClasses),
            "focused": unwrap_bool(focused),
            "htmlFor": from_opt(htmlFor),
            "margin": from_opt(option_map(Margin.to_string, margin)),
            "required": unwrap_bool(required),
            "shrink": unwrap_bool(shrink),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Input = {
  [@bs.module "material-ui/Input"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~disableUnderline: option(bool)=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~id: option(string)=?,
        ~autoFocus: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~value: option(string)=?,
        ~onChange: option(ReactEventRe.Form.t => unit)=?,
        ~placeholder: option(string)=?,
        ~className: option(string)=?,
        ~inputType: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "disableUnderline": unwrap_bool(disableUnderline),
            "disabled": unwrap_bool(disabled),
            "error": unwrap_bool(error),
            "id": from_opt(id),
            "fullWidth": unwrap_bool(fullWidth),
            "autoFocus": unwrap_bool(autoFocus),
            "style": from_opt(style),
            "placeholder": from_opt(placeholder),
            "className": from_opt(className),
            "type": from_opt(inputType),
            "value": from_opt(value),
            "onChange": from_opt(onChange),
          }
        ),
      children,
    );
};

module LinearProgress = {
  [@bs.module "material-ui/Progress"]
  external reactClass : ReasonReact.reactClass = "LinearProgress";
  let make =
      (
        ~style: option(ReactDOMRe.style)=?,
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~color: option(string)=?,
        ~value: option(int)=?,
        ~valueBuffer: option(int)=?,
        ~mode: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "style": from_opt(style),
            "mode": from_opt(mode),
            "color": from_opt(color),
            "valueBuffer": from_opt(valueBuffer),
            "value": from_opt(value),
            "className": from_opt(className),
          }
        ),
      children,
    );
};

module ListItemAvatar = {
  [@bs.module "material-ui/List"]
  external reactClass : ReasonReact.reactClass = "ListItemAvatar";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "style": from_opt(style),
            "className": from_opt(className),
          }
        ),
      children,
    );
};

module ListItemIcon = {
  [@bs.module "material-ui/List"]
  external reactClass : ReasonReact.reactClass = "ListItemIcon";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "style": from_opt(style),
            "className": from_opt(className),
          }
        ),
      children,
    );
};

module ListItemSecondaryAction = {
  [@bs.module "material-ui/List"]
  external reactClass : ReasonReact.reactClass = "ListItemSecondaryAction";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "style": from_opt(style),
            "className": from_opt(className),
          }
        ),
      children,
    );
};

module ListItemText = {
  [@bs.module "material-ui/List"]
  external reactClass : ReasonReact.reactClass = "ListItemText";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~disableTypography: option(bool)=?,
        ~inset: option(bool)=?,
        ~primary: option(ReasonReact.reactElement)=?,
        ~secondary: option(ReasonReact.reactElement)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "disableTypography": unwrap_bool(disableTypography),
            "inset": unwrap_bool(inset),
            "primary": from_opt(primary),
            "secondary": from_opt(secondary),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module ListItem = {
  [@bs.module "material-ui/List"]
  external reactClass : ReasonReact.reactClass = "ListItem";
  let make =
      (
        ~button: option(bool)=?,
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~dense: option(bool)=?,
        ~disabled: option(bool)=?,
        ~disableGutters: option(bool)=?,
        ~divider: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        ~href: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "button": unwrap_bool(button),
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "dense": unwrap_bool(dense),
            "disabled": unwrap_bool(disabled),
            "disableGutters": unwrap_bool(disableGutters),
            "divider": unwrap_bool(divider),
            "style": from_opt(style),
            "onClick": from_opt(onClick),
            "href": from_opt(href),
          }
        ),
      children,
    );
};

module ListSubheader = {
  module Color = {
    type t =
      | Default
      | Inherit
      | Primary;
    let to_string =
      fun
      | Default => "default"
      | Inherit => "inherit"
      | Primary => "primary";
  };
  [@bs.module "material-ui/List"]
  external reactClass : ReasonReact.reactClass = "ListSubheader";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~color: option(Color.t)=?,
        ~disableSticky: option(bool)=?,
        ~inset: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "color": from_opt(option_map(Color.to_string, color)),
            "disableSticky": unwrap_bool(disableSticky),
            "inset": unwrap_bool(inset),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module List = {
  [@bs.module "material-ui/List"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~dense: option(bool)=?,
        ~disablePadding: option(bool)=?,
        ~subheader: option(ReasonReact.reactElement)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "dense": unwrap_bool(dense),
            "disablePadding": unwrap_bool(disablePadding),
            "subheader": from_opt(subheader),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Menu = {
  [@bs.module "material-ui/Menu"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~anchorEl: option(Dom.element)=?,
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~onClose: option(ReactEventRe.Mouse.t => unit)=?,
        ~open_: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~onEnter: option(Dom.element => unit)=?,
        ~onEntered: option(Dom.element => unit)=?,
        ~onExit: option(Dom.element => unit)=?,
        ~menuListProps: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "onClose": from_opt(onClose),
            "open": unwrap_bool(open_),
            "anchorEl": from_opt(anchorEl),
            "style": from_opt(style),
            "onEnter": from_opt(onEnter),
            "onEntered": from_opt(onEntered),
            "onExit": from_opt(onExit),
            "MenuListProps": from_opt(menuListProps),
          }
        ),
      children,
    );
};

module MenuItem = {
  [@bs.module "material-ui/Menu"]
  external reactClass : ReasonReact.reactClass = "MenuItem";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~role: option(string)=?,
        ~selected: option(bool)=?,
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~value: option([ | `String(string) | `Int(int)])=?,
        ~dense: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "role": from_opt(role),
            "selected": unwrap_bool(selected),
            "dense": unwrap_bool(dense),
            "onClick": from_opt(onClick),
            "style": from_opt(style),
            "value": from_opt(option_map(unwrapValue, value)),
          }
        ),
      children,
    );
};

module Paper = {
  [@bs.module "material-ui/Paper"]
  external toolbar : ReasonReact.reactClass = "default";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~elevation: option(int)=?,
        ~square: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=toolbar,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "elevation": from_opt(elevation),
            "square": unwrap_bool(square),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Select = {
  [@bs.module "material-ui/Select"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~autoWidth: option(bool)=?,
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~displayEmpty: option(bool)=?,
        ~input: option(ReasonReact.reactElement)=?,
        ~inputClasses: option(Js.t({..}))=?,
        ~native: option(bool)=?,
        ~multiple: option(bool)=?,
        ~menuProps: option(Js.t({..}))=?,
        ~value:
           option(
             [
               | `Int(int)
               | `IntArray(array(int))
               | `String(string)
               | `StringArray(array(string))
             ],
           )=?,
        ~style: option(ReactDOMRe.style)=?,
        /* Input Props*/
        ~disableUnderline: option(bool)=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~autoFocus: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~onChange: option(ReactEventRe.Form.t => unit)=?,
        ~placeholder: option(string)=?,
        ~inputType: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "autoWidth": unwrap_bool(autoWidth),
            "classes": from_opt(classes),
            "className": from_opt(className),
            "displayEmpty": unwrap_bool(displayEmpty),
            "input": from_opt(input),
            "InputClasses": from_opt(inputClasses),
            "native": unwrap_bool(native),
            "multiple": unwrap_bool(multiple),
            "MenuProps": from_opt(menuProps),
            "value": from_opt(option_map(unwrapValue, value)),
            "style": from_opt(style),
            /* TODO: Input Props: find a way to rectactor props duplication. */
            "disableUnderline": unwrap_bool(disableUnderline),
            "disabled": unwrap_bool(disabled),
            "error": unwrap_bool(error),
            "fullWidth": unwrap_bool(fullWidth),
            "autoFocus": unwrap_bool(autoFocus),
            "placeholder": from_opt(placeholder),
            "type": from_opt(inputType),
            "onChange": from_opt(onChange),
          }
        ),
      children,
    );
};

module Fade = {
  [@bs.module "material-ui/transitions/Fade"]
  external fade : ReasonReact.reactClass = "default";

  let make =
      (
        ~in_: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~onExited: option(unit => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=fade,
      ~props=
        Js.Nullable.(
          {
            "in": unwrap_bool(in_),
            "onExited": from_opt(onExited),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Slide = {
  [@bs.module "material-ui/transitions/Slide"]
  external slide : ReasonReact.reactClass = "default";
  module Direction = {
    type t =
      | Up
      | Down
      | Left
      | Right;
    let to_string =
      fun
      | Up => "up"
      | Down => "down"
      | Left => "left"
      | Right => "right";
  };
  let make =
      (
        ~in_: option(bool)=?,
        ~direction_: option(Direction.t)=?,
        ~timeout:
           option(
             {
               .
               "enter": float,
               "exit": float,
             },
           )=?,
        ~style: option(ReactDOMRe.style)=?,
        ~onExit: option(unit => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=slide,
      ~props=
        Js.Nullable.(
          {
            "in": unwrap_bool(in_),
            "direction":
              from_opt(option_map(Direction.to_string, direction_)),
            "timeout": from_opt(timeout),
            "onExit": from_opt(onExit),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Snackbar = {
  [@bs.module "material-ui/Snackbar"]
  external snackbar : ReasonReact.reactClass = "default";
  module AnchorOrigin = {
    type t =
      | TopRight
      | TopCenter
      | TopLeft
      | BottomRight
      | BottomCenter
      | BottomLeft;
    let toObject =
      fun
      | TopRight => {"vertical": "top", "horizontal": "right"}
      | TopCenter => {"vertical": "top", "horizontal": "center"}
      | TopLeft => {"vertical": "top", "horizontal": "left"}
      | BottomRight => {"vertical": "bottom", "horizontal": "right"}
      | BottomCenter => {"vertical": "bottom", "horizontal": "center"}
      | BottomLeft => {"vertical": "bottom", "horizontal": "left"};
  };
  let make =
      (
        ~open_: option(bool)=?,
        ~anchorOrigin: option(AnchorOrigin.t)=?,
        ~autoHideDuration: option(int)=?,
        ~onClose: option((ReactEventRe.Mouse.t, string) => unit)=?,
        ~onExit: option(unit => unit)=?,
        ~onExited: option(unit => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=snackbar,
      ~props=
        Js.Nullable.(
          {
            "open": unwrap_bool(open_),
            "autoHideDuration": from_opt(autoHideDuration),
            "onClose": from_opt(onClose),
            "onExit": from_opt(onExit),
            "onExited": from_opt(onExited),
            "style": from_opt(style),
            "anchorOrigin":
              from_opt(option_map(AnchorOrigin.toObject, anchorOrigin)),
          }
        ),
      children,
    );
};

module TableBody = {
  [@bs.module "material-ui/Table"]
  external toolbar : ReasonReact.reactClass = "TableBody";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=toolbar,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module TableCell = {
  module Padding = {
    type t =
      | Default
      | Checkbox
      | Dense
      | None;
    let to_string =
      fun
      | Default => "default"
      | Checkbox => "checkbox"
      | Dense => "dense"
      | None => "none";
  };
  [@bs.module "material-ui/Table"]
  external toolbar : ReasonReact.reactClass = "TableCell";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~numeric: option(bool)=?,
        ~padding: option(Padding.t)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=toolbar,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "numeric": unwrap_bool(numeric),
            "padding": from_opt(option_map(Padding.to_string, padding)),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module TableFooter = {
  [@bs.module "material-ui/Table"]
  external toolbar : ReasonReact.reactClass = "TableFooter";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=toolbar,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module TableHead = {
  [@bs.module "material-ui/Table"]
  external toolbar : ReasonReact.reactClass = "TableHead";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=toolbar,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module TableRow = {
  [@bs.module "material-ui/Table"]
  external toolbar : ReasonReact.reactClass = "TableRow";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~hover: option(bool)=?,
        ~selected: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEventRe.Mouse.t => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=toolbar,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "hover": unwrap_bool(hover),
            "selected": unwrap_bool(selected),
            "style": from_opt(style),
            "onClick": from_opt(onClick),
            "onDoubleClick": from_opt(onDoubleClick),
          }
        ),
      children,
    );
};

module Table = {
  [@bs.module "material-ui/Table"]
  external toolbar : ReasonReact.reactClass = "default";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=toolbar,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module TextField = {
  [@bs.module "material-ui/TextField"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~autoComplete: option(string)=?,
        ~autoFocus: option(bool)=?,
        ~className: option(string)=?,
        ~defaultValue: option(string)=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~_FormHelperTextProps: option(Js.t({..}))=?,
        ~fullWidth: option(bool)=?,
        /* TODO: change type to match Node */
        ~helperText: option(string)=?,
        ~helperTextClassName: option(string)=?,
        ~id: option(string)=?,
        /* Material-UI have two pais of similar props with different case. See: Git hub issue https://github.com/callemall/material-ui/issues/8232 */
        ~inputClassName: option(string)=?,
        ~_InputClassName: option(string)=?,
        ~_InputLabelProps: option(Js.t({..}))=?,
        ~inputProps: option(Js.t({..}))=?,
        ~_InputProps: option(Js.t({..}))=?,
        /* TODO: change type to match ref callback (see https://reasonml.github.io/reason-react/docs/en/react-ref.html) */
        ~inputRef=?,
        /* TODO: change type to match Node */
        ~label: option(string)=?,
        ~labelClassName: option(string)=?,
        ~multiline: option(bool)=?,
        ~name: option(string)=?,
        ~onChange: option(ReactEventRe.Form.t => unit)=?,
        ~placeholder: option(string)=?,
        ~required: option(bool)=?,
        /* TODO: change type to match ref callback (see https://reasonml.github.io/reason-react/docs/en/react-ref.html) */
        ~rootRef=?,
        ~rows: option([ | `Int(int) | `String(string)])=?,
        ~rowsMax: option([ | `Int(int) | `String(string)])=?,
        ~select: option(bool)=?,
        ~_SelectProps: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~value: option([ | `Int(int) | `String(string) | `Float(float)])=?,
        ~margin: option(Margin.t)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "autoComplete": from_opt(autoComplete),
            "autoFocus": unwrap_bool(autoFocus),
            "className": from_opt(className),
            "defaultValue": from_opt(defaultValue),
            "disabled": unwrap_bool(disabled),
            "error": unwrap_bool(error),
            "FormHelperTextProps": from_opt(_FormHelperTextProps),
            "fullWidth": unwrap_bool(fullWidth),
            "helperText": from_opt(helperText),
            "helperTextClassName": from_opt(helperTextClassName),
            "id": from_opt(id),
            "inputClassName": from_opt(inputClassName),
            "InputClassName": from_opt(_InputClassName),
            "InputLabelProps": from_opt(_InputLabelProps),
            "inputProps": from_opt(inputProps),
            "InputProps": from_opt(_InputProps),
            "inputRef": from_opt(inputRef),
            "label": from_opt(label),
            "labelClassName": from_opt(labelClassName),
            "multiline": unwrap_bool(multiline),
            "name": from_opt(name),
            "onChange": from_opt(onChange),
            "placeholder": from_opt(placeholder),
            "required": unwrap_bool(required),
            "rootRef": from_opt(rootRef),
            "rows": from_opt(option_map(unwrapValue, rows)),
            "rowsMax": from_opt(option_map(unwrapValue, rowsMax)),
            "select": unwrap_bool(select),
            "SelectProps": from_opt(_SelectProps),
            "type": from_opt(_type),
            "value": from_opt(option_map(unwrapValue, value)),
            "margin": from_opt(option_map(Margin.to_string, margin)),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Toolbar = {
  [@bs.module "material-ui/Toolbar"]
  external toolbar : ReasonReact.reactClass = "default";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~disableGutters=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=toolbar,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "disableGutters": unwrap_bool(disableGutters),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Tooltip = {
  module Placement = {
    type t =
      | BottomEnd
      | BottomStart
      | Bottom
      | LeftEnd
      | LeftStart
      | Left
      | RightEnd
      | RightStart
      | Right
      | TopEnd
      | TopStart
      | Top;
    let to_string =
      fun
      | BottomEnd => "bottom-end"
      | BottomStart => "bottom-start"
      | Bottom => "bottom"
      | LeftEnd => "left-end"
      | LeftStart => "left-start"
      | Left => "left"
      | RightEnd => "right-end"
      | RightStart => "right-start"
      | Right => "right"
      | TopEnd => "top-end"
      | TopStart => "top-start"
      | Top => "top";
  };
  [@bs.module "material-ui/Tooltip"]
  external toolbar : ReasonReact.reactClass = "default";
  let make =
      (
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~disableTriggerFocus: option(bool)=?,
        ~disableTriggerHover: option(bool)=?,
        ~disableTriggerTouch: option(bool)=?,
        ~id: option(string)=?,
        ~onClose: option(unit => unit)=?,
        ~onOpen: option(unit => unit)=?,
        ~_open: option(bool)=?,
        /* TODO: is actually a Node */
        ~title: option(string)=?,
        ~enterDelay: option(int)=?,
        ~leaveDelay: option(int)=?,
        ~placement: option(Placement.t)=?,
        ~popperProps: option(Js.t({..}))=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=toolbar,
      ~props=
        Js.Nullable.(
          {
            "classes": from_opt(classes),
            "className": from_opt(className),
            "disableTriggerFocus": unwrap_bool(disableTriggerFocus),
            "disableTriggerHover": unwrap_bool(disableTriggerHover),
            "disableTriggerTouch": unwrap_bool(disableTriggerTouch),
            "id": from_opt(id),
            "onClose": from_opt(onClose),
            "onOpen": from_opt(onOpen),
            "open": unwrap_bool(_open),
            "title": from_opt(title),
            "enterDelay": from_opt(enterDelay),
            "leaveDelay": from_opt(leaveDelay),
            "placement":
              from_opt(option_map(Placement.to_string, placement)),
            "PopperProps": from_opt(popperProps),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Typography = {
  [@bs.module "material-ui/Typography"]
  external typography : ReasonReact.reactClass = "default";
  let make =
      (
        ~align: option(string)=?,
        ~classes: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(string)=?,
        ~color: option(string)=?,
        ~gutterBottom=?,
        ~headlineMapping: option(Js.t({..}))=?,
        ~noWrap=?,
        ~paragraph=?,
        ~_type: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=typography,
      ~props=
        Js.Nullable.(
          {
            "align": from_opt(align),
            "classes": from_opt(classes),
            "className": from_opt(className),
            "component": from_opt(component),
            "color": from_opt(color),
            "gutterBottom": unwrap_bool(gutterBottom),
            "headlineMapping": from_opt(headlineMapping),
            "noWrap": unwrap_bool(noWrap),
            "paragraph": unwrap_bool(paragraph),
            "type": from_opt(_type),
            "style": from_opt(style),
          }
        ),
      children,
    );
};

module Zoom = {
  [@bs.module "material-ui/transitions/Zoom"]
  external zoom : ReasonReact.reactClass = "default";
  let make =
      (~in_: option(bool)=?, ~onExited: option(unit => unit)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=zoom,
      ~props=
        Js.Nullable.(
          {"in": unwrap_bool(in_), "onExited": from_opt(onExited)}
        ),
      children,
    );
};
