### Designing the API




### Interfaces
`DisplayInterface`
* Will be the same thing as `DirectDisplay` but takes in a framebuffer to where to draw the pixel
* Basically you will have a function like `hal::DisplayInterface::DrawPixel(buffer, x, y, color)`
    * The user should be able to specify the buffer they are writing too and what position to draw our pixel

`DirectDisplay`
* Same as DisplayInterface, only thing is the user does not need to specify a framebuffer
* Meaning they can just utilize the frame buffer that is used when calling the display
* Example would probably be like `DirectDisplay::DrawPixel(x, y, color)`

* Another thing to note (and this applies to both DirectDisplay and DisplayInterface) is that the user probably wont call Display::Update(display, ...) that often
* Here are some of the things that `DisplayInterface::Update(display, frame)` or `DirectDisplay::Update(display)` will be used for
    * Executing updating our frames if there are issues that occur when trying to upload our pixels.


Abstraction Layer
    * Regarding the abstraction, essentially the user does need to worry about hardware-related specifications
    * This will all be handled by the drivers

    Here are some ideas for the Abstraction Layer to Note!
    `SSD1331 display1(spi, cs);`
        * Which takes in our serial communication and our cs register that activates when this display gets called
        * Purpose of `cs` is to allow letting the interface know what display will be activated and where to draw/render our data to which display
            that the `cs` register has been activated.

    Another thing to Point out
        * When having this abstract layer, I may create a graphics API called `DisplayGraphics`
        * This will handle graphics geometry, how to reference to pixels in terms of the geometry needed to render to that display
        * Although this is something I'd like to consider once, this goes

Function Calls
* These are function calls that were currently discussed

`
SSD1331 display;
auto frames = CreateFrames<180, 64>(display1);
`
    * This function takes our display, and returns a new frame buffer.
    * Framebuffer will be used to draw/render our pixel data too.
    * Specifying the W x H and the display that we would like to get our reference frames from that display.

NOTE -- Another thing to note is that these draw commands are only pixels, but similarily the DrawLine, DrawCircle, DrawRect, and DrawTriangle would be the same/similar

`DirectDisplay::DrawPixel(display, x, y, color);`
    * Drawing our pixel to our display without specfying the frame buffer that we would like to draw our pixels at
    * Though when we call this function, we may need to specify this function call afterwards, `DisplayInterface::Update(display, frames)`
    * Reason for this is beacuse we care about our frame that will be rendering pixels too.
    * Especially in cases that the display may have a smaller display dimensions or larger, where we need to modify out framebuffers to fit those specific displays.

`DirectInterface::DrawPixel(display, x, y, color);`
    * Instead of passing our frame, we are specfying which display we would like to draw our pixel too
    * Reason is because we do not need to know anything about the current framebuffer the display is rendering the pixels too