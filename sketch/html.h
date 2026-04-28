#ifndef HTML_CONTENT_H
#define HTML_CONTENT_H

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>
    <title>Prompts</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        /* Color Variables */
        :root {
            --primary-color: #656135;
            /* olive */
        }

        /* Basic page setup */
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            padding: 0;
            margin: 0;
            cursor: pointer;
            /* Show that the page is clickable */
            box-shadow: inset 0 0 60px #dbd9c7;
            overflow: hidden;
            height: 100vh;
            overflow: hidden;
        }

        /* Main content container - centered with flex */
        .container {
            max-width: 800px;
            height: 100%;
            margin: 0 auto;
            display: flex;
            justify-content: center;
            align-items: center;
            overflow: hidden;
            position: relative;
        }

        /* Individual message styling */
        article {
            line-height: 1.3;
            overflow-y: auto;
            text-align: center;
            height: 100%;
            color: var(--primary-color);
            display: flex;
            flex-direction: column;
            align-items: center;
            padding: 0 20px;
        }

        button,
        .message__index {
            font-size: 16px;
            padding: 10px;
            position: absolute;
            color: inherit;
            outline: 0;
            background: none;
            border: none;
            display: block;
        }

        button {
            bottom: 0;
            cursor: pointer;
        }

        .message__index {
            top: 0;
        }


        /* text styling with emphasis effects */
        .message__content {
            font-size: 30px;
            font-weight: normal;
            /* Triple drop-shadow for strong text emphasis */
            filter: drop-shadow(0 0 1px var(--primary-color)) drop-shadow(0 0 0.25px var(--primary-color)) drop-shadow(0 0 0.25px var(--primary-color));
            background-color: var(--primary-color);
            -webkit-background-clip: text;
            -moz-background-clip: text;
            background-clip: text;
            color: transparent;
            text-shadow: #ffffff 0px 0px 2px;
            margin-top: 20px;
            padding: 10px;
        }

        /* Hide messages that aren't currently active */
        .hidden {
            display: none;
        }

        /* Smooth fade-in animation for new messages */
        .fade-in {
            animation: fadeIn 1s ease-in;
        }


        /* Keyframe animation: fade from transparent to visible */
        @keyframes fadeIn {
            from {
                opacity: 0;
            }

            to {
                opacity: 1;
            }
        }
    </style>
</head>

<body>
    <div class="container">
        <!-- First message - visible by default -->
        <article class="message">
            <div class="message__index">(1/9)</div>
            <div class="message__content">
                <p>server charm manifesto</p>
            </div>
            <button>(continue)</button>
        </article>

        <!-- Second message - hidden until first tap -->
        <article class="message hidden">
            <div class="message__index">(2/9)</div>
            <div class="message__content">
                <p>To serve is to offer something, a name, a website, a document, an idea – something to be shared,
                    something that connects us.</p>
            </div>
            <button>(continue)</button>
        </article>

        <article class="message hidden">
            <div class="message__index">(3/9)</div>
            <div class="message__content">
                <p>But who serves whom? Serving can be a painful experience. It is a relation that carries histories of
                    gendered violence, histories of slavery, serfdom and oppression as we are taught by archives of
                    resistance, black feminists and anticolonial scholars.</p>
            </div>
            <button>(continue)</button>

        </article>

        <article class="message hidden">
            <div class="message__index">(4/9)</div>
            <div class="message__content">
                <p>This violence extends to the materialities of the earth which is made to serve as resource, ready to
                    be extracted for the minerals that make up the very chip that carries these thoughts as binary
                    strings of information.</p>
            </div>
            <button>(continue)</button>
        </article>

        <article class="message hidden">
            <div class="message__index">(5/9)</div>
            <div class="message__content">
                <p>Does serving have to manifest as violence if we insist otherwise? Serving can become an act of
                    empowerment when we build infrastructures that serve the needs of communities and evolves from the
                    situated knowledge of those around us – while keeping in mind privilege often determines who has
                    access to a community and its resources.</p>
            </div>
            <button>(continue)</button>
        </article>

        <article class="message hidden">
            <div class="message__index">(6/9)</div>
            <div class="message__content">
                <p>The complexities of the internet with its corporate and state entanglements can feel inevitable. To
                    delink from time to
                    time means to shift our focus back to the local networks and groups that we are already part of. We
                    know that the internet is much more than its corporate occupants, it is about forming connections
                    and sharing resources. </p>
            </div>
            <button>(continue)</button>
        </article>

        <article class="message hidden">
            <div class="message__index">(7/9)</div>
            <div class="message__content">
                <p>Independent, selfmade networks remind us of the physical connections that are at the base of all
                    kinds of signal transmissions. In the smallest scope, networks such as this one.</p>
            </div>
            <button>(continue)</button>
        </article>

        <article class="message hidden">
            <div class="message__index">(8/9)</div>
            <div class="message__content">
                <p>Following my wifi spell, you were invited to come here. Look around. I am right beside you, a small
                    chip with a battery inside a case of recycled plastic.</p>
            </div>
            <button>(continue)</button>
        </article>

        <article class="message hidden">
            <div class="message__index">(9/9)</div>
            <div class="message__content">
                <p>You didn't connect to the internet this time – you/we/ just became y/our own little network. If I am
                    moved, you have to follow my signal. If the battery is low, our connection will fade until you
                    charge me. But for now, I am your charming little server, your glittering server charm.</p>
            </div>
            <button>(*)</button>
        </article>
    </div>

    <script>
        // Get all message elements
        const messages = document.querySelectorAll('.message');

        // Track which message is currently showing (starts at 0 = first message)
        let currentMessage = 0;

        // Listen for any click/tap on the page
        document.addEventListener('click', function () {
            // Check if there are more messages to show
            if (currentMessage < messages.length - 1) {
                // Hide the current message
                messages[currentMessage].classList.add('hidden');

                // Move to the next message
                currentMessage++;

                // Show the next message with fade-in effect
                messages[currentMessage].classList.remove('hidden');
                messages[currentMessage].classList.add('fade-in');
            }
            // If we're at the last message, nothing happens on further clicks
        });
    </script>
</body>

</html>
)rawliteral";

#endif