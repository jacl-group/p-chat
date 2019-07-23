HTTPRequestHandlerFactory
* The factory can only look at what is requested from the URL. 
  * If a form uses method="get", then it will have the form values available.
  * If a form uses method="post", then the only way to see the form values is in the 
    RequestHandler.
* Since I prefer to use form method="post" becasue it does not show the form variables, then
  I have to defer processing of form data to the RequestHandler.
  
To allow the RequestHandler to send more than one page, I am introducing the concept of the
HTMLPage class which will be used by HTTPRequestHandler.handleRequest().

