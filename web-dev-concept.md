**Cross-Origin Resource Sharing**

Cross-Origin Resource Sharing (CORS) is a mechanism that uses additional HTTP headers 
to tell a browser to let a web application running at one origin (domain) have 
permission to access selected resources from a server at a different origin. A web 
application executes a cross-origin HTTP request when it requests a resource that 
has a different origin (domain, protocol, and port) than its own origin.

For security reasons, browsers restrict cross-origin HTTP requests initiated from within
scripts.

![](https://mdn.mozillademos.org/files/14295/CORS_principle.png)

The CORS mechanism supports secure cross-origin requests and data transfers between browsers 
and web servers. Modern browsers use CORS in an API container such as `XMLHttpRequest` or Fetch 
to help mitigate the risks of cross-origin HTTP requests.


**Same-Origin Policy**

The same-origin policy is a critical security mechanism that restricts how a 
document or script loaded from one origin can interact with a resource from another 
origin. It helps isolate potentially malicious documents, reducing possible attack 
vectors.

**Definition of an Origin**

Two URLs have the same origin if the *protocol*, *port* (if specified), and *host* 
are the same for both. You may see this referenced as the "scheme/host/port tuple",
or just "tuple".

**Cross-Origin Network Access**

The same-origin policy controls interactions between two different origins, such 
as when you use `XMLHttpRequest` or an `<img>` element. These interactions are 
typically placed into three categories:

* Cross-origin writes are typically allowed. Examples are links, redirects, and 
form submissions. Some HTTP requests require preflight.

* Cross-origin embedding is typically allowed.
    
    * JavaScript with `<script src="…"></script>`. Error details for syntax errors 
    are only available for same-origin scripts.
    
    * CSS applied with `<link rel="stylesheet" href="…">`. Due to the relaxed syntax 
    rules of CSS, cross-origin CSS requires a correct `Content-Type` header. 
    Restrictions vary by browser: (CVE-2010-0051)
    
    * Images displayed by `<img>`.
    
    * Meida played by `<video>` and `<audio>`.
    
    * Plugins embedded with `<object>`,`<embed>`,`<applet>`.
    
    * Fonts applied with `@font-face`. Some browsers allow cross-origin fonts, others 
    require same-origin.
    
    * Anything embedded by `<frame>` and `<iframe>. Sites can use the `X-Frame-Options` 
    header to prevent cross-origin framing.

* Cross-origin reads are typically disallowed, but read access is often leaked by 
embedding. For example, you can read the dimensions of an embedded image, the 
actions of an embedded script, or the availability of an embedded resource.

**How to allow cross-origin access**

Use CORS to allow cross-origin access. CORS is a part of HTTP that lets servers specify 
what hosts are permitted to load content from that server.

**How to block cross-origin access**

* To prevent cross-origin writes, check an unguessable token in the request — known as 
a __**Cross-Site Request Forgery (CSRF)**__ token. You must prevent cross-origin reads 
of pages that require this token.

* To prevent cross-origin reads of a resource, ensure that it is not embeddable. It is 
often necessary to prevent embedding because embedding a resource always leaks some 
information about it.

* To prevent cross-origin embeds, ensure that your resource cannot be interpreted as one 
of the embeddable formats listed above. Browsers may not respect the `Content-Type` header. 
For example, if you point a `<script>` tag at an HTML document, the browser will try to parse 
the HTML as JavaScript. When your resource is not an entry point to your site, you can also 
use a CSRF token to prevent embedding.

**Cross-Origin Data Storage Access**

Access to data stored in the browser such as localStorage and IndexedDB are separated by origin. 
Each origin gets its own separate storage, and JavaScript in one origin cannot read from or write 
to the storage belonging to another origin.

Cookies use a separate definition of origins. A page can set a cookie for its own domain or any 
parent domain, as long as the parent domain is not a public suffix. Firefox and Chrome use the 
Public Suffix List to determine if a domain is a public suffix. Internet Explorer uses its own 
internal method to determine if a domain is a public suffix. The browser will make a cookie 
available to the given domain including any sub-domains, no matter which protocol (HTTP/HTTPS) 
or port is used. When you set a cookie, you can limit its availability using the Domain, Path, 
Secure and Http-Only flags. When you read a cookie, you cannot see from where it was set. Even 
if you use only secure https connections, any cookie you see may have been set using an insecure 
connection.

**Public Suffix List**

A "public suffix" is one under which Internet users can (or historically could) directly register 
names. Some examples of public suffixes are .com, .co.uk and pvt.k12.ma.us. The Public Suffix List 
is a list of all known public suffixes.

it allows browsers to:

* Avoid privacy-damaging "supercookies" being set for high-level domain name suffixes

* Highlight the most important part of a domain name in the user interface

* Accurately sort history entries by site

**Fetch API**

The Fetch API provides an interface for fetching resources (including across the network).
It will seem familiar to anyone who has used `XMLHttpRequest`, but the new API provides a 
more powerful and flexible feature set.

