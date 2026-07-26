# Conventions

## Null

Nulls are ALWAYS represented by `undefined`, NEVER `null`. There is a distinction, and there are places where `null` WOULD have made more sense than `undefined`, but it's too subtle.

## Error Handling, Parameter Validation

To-date, not much consideration has been put into this. Errors *usually* don't crash the whole application *(like they did during most of the development process... fun times...)*, but it still happens more frequently than I would like.

This is probably going to improve a little, but it is VERY unlikely that any reported issues will be fixed if they already trigger TypeScript errors. In the same vein, if a usage error can be "fixed" by updating TypeScript to catch the error at design-time instead of runtime, then that is VERY likely all that this project will do about it.

## Hooks

Hooks are ALWAYS called with a single `object`-type argument. *Conventionally, this argument is named `args`, but you can call it whatever you like.* All useful values that your hook might need will be properties on that object, NEVER the object itself.

If a hook argument is passed by (non-const) reference in C++, then your handler can modify it by writing to the property on `args`. Otherwise, you MUST treat it as read-only.

If a hook method returns a value in C++, then the argument will have a writable property (named `__return` at the time of writing) that scripts can use to control the value that will be returned. *The handler's actual return value will be ignored. The purpose of this is to have a consistent and coherent story when multiple handlers are present.*
