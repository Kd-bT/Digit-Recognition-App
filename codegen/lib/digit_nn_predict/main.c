/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 29-Sep-2015 21:33:52
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "digit_nn_predict.h"
#include "main.h"
#include "digit_nn_predict_terminate.h"
#include "digit_nn_predict_initialize.h"

#include <stdio.h>
#include <stdlib.h>
#include <libwebsockets.h>

/* Function Declarations */
static void argInit_1x784_real_T(double result[784]);
static double argInit_real_T(void);
static void main_digit_nn_predict(void);

/* Function Definitions */

/*
 * Arguments    : double result[784]
 * Return Type  : void
 */
static void argInit_1x784_real_T(double result[784])
{
  int b_j1;

  /* Loop over the array to initialize each element. */
  for (b_j1 = 0; b_j1 < 784; b_j1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[b_j1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_digit_nn_predict(void)
{
  double dv2[784];
  double p;

  /* Initialize function 'digit_nn_predict' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'digit_nn_predict'. */
  argInit_1x784_real_T(dv2);
  p = digit_nn_predict(dv2);
  printf("%f\n", p);
}

/* Socket Code */
static int callback_http(struct libwebsocket_context * this,
                         struct libwebsocket *wsi,
                         enum libwebsocket_callback_reasons reason, void *user,
                         void *in, size_t len)
{
    return 0;
}

static int callback_predict(struct libwebsocket_context * this,
                                   struct libwebsocket *wsi,
                                   enum libwebsocket_callback_reasons reason,
                                   void *user, void *in, size_t len)
{
    printf("In predict %d\n", reason);
    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED: // just log message that someone is connecting
            printf("connection established\n");
            break;
        case LWS_CALLBACK_RECEIVE: { // the funny part
            // create a buffer to hold our response
            // it has to have some pre and post padding. You don't need to care
            // what comes there, libwebsockets will do everything for you. For more info see
            // http://git.warmcat.com/cgi-bin/cgit/libwebsockets/tree/lib/libwebsockets.h#n597
            /*unsigned char *buf = (unsigned char*) malloc(LWS_SEND_BUFFER_PRE_PADDING + len +
                                                         LWS_SEND_BUFFER_POST_PADDING);
           
            int i;
           
            // pointer to `void *in` holds the incomming request
            // we're just going to put it in reverse order and put it in `buf` with
            // correct offset. `len` holds length of the request.
            for (i=0; i < len; i++) {
                buf[LWS_SEND_BUFFER_PRE_PADDING + (len - 1) - i ] = ((char *) in)[i];
            }
           
            // log what we recieved and what we're going to send as a response.
            // that disco syntax `%.*s` is used to print just a part of our buffer
            // http://stackoverflow.com/questions/5189071/print-part-of-char-array
            printf("received data: %s, replying: %.*s\n", (char *) in, (int) len,
                 buf + LWS_SEND_BUFFER_PRE_PADDING);

            // send response
            // just notice that we have to tell where exactly our response starts. That's
            // why there's `buf[LWS_SEND_BUFFER_PRE_PADDING]` and how long it is.
            // we know that our response has the same length as request because
            // it's the same message in reverse order.
            libwebsocket_write(wsi, &buf[LWS_SEND_BUFFER_PRE_PADDING], len, LWS_WRITE_TEXT);
           
            // release memory back into the wild
            free(buf);*/

            double p = 5.0000;
            if (p == 10)
            {
              p = 0;
            }

            char count[2];
            snprintf(count,2,"%f",p);
            
            int len = (int) strlen(count);
            unsigned char *buf = (unsigned char*) malloc(LWS_SEND_BUFFER_PRE_PADDING + len +
                                                         LWS_SEND_BUFFER_POST_PADDING);
            
            int i;
            for (i=0; i < len; i++) {
                buf[LWS_SEND_BUFFER_PRE_PADDING + i ] = count[i];
            }

            libwebsocket_write(wsi, &buf[LWS_SEND_BUFFER_PRE_PADDING], len, LWS_WRITE_TEXT);

            free(buf);
            break;
        }
        default:
            break;
    }
   
   
    return 0;
}

static struct libwebsocket_protocols protocols[] = {
    /* first protocol must always be HTTP handler */
    {
        "http-only",   // name
        callback_http, // callback
        0              // per_session_data_size
    },
    {
        "predict-protocol", // protocol name - very important!
        callback_predict,   // callback
        0                          // we don't use any per session data

    },
    {
        NULL, NULL, 0   /* End of list */
    }
};

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  struct lws_context_creation_info info;

  // server url will be http://localhost:9000
  int port = 9000;
  const char *interface = NULL;
  int opts = 0;

  memset(&info, 0, sizeof info);
  info.port = port;
  info.iface = interface;
  info.protocols = protocols;
  info.extensions = libwebsocket_get_internal_extensions();
  //if (!use_ssl) {
      info.ssl_cert_filepath = NULL;
      info.ssl_private_key_filepath = NULL;
  //} else {
  //  info.ssl_cert_filepath = LOCAL_RESOURCE_PATH"/libwebsockets-test-server.pem";
  //  info.ssl_private_key_filepath = LOCAL_RESOURCE_PATH"/libwebsockets-test-server.key.pem";
  //}
  info.gid = -1;
  info.uid = -1;
  info.options = opts;

  struct libwebsocket_context *context = libwebsocket_create_context(&info);
 
  if (context == NULL) {
      fprintf(stderr, "libwebsocket init failed\n");
      return -1;
  }
 
  printf("starting server...\n");
 
  // infinite loop, to end this server send SIGTERM. (CTRL+C)
  while (1) {
      libwebsocket_service(context, 50);
      // libwebsocket_service will process all waiting events with their
      // callback functions and then wait 50 ms.
      // (this is a single threaded webserver and this will keep our server
      // from generating load while there are not requests to process)
  }
 
  libwebsocket_context_destroy(context);


  /* Rest of code runs dummy program */
  //(void)argc;
  //(void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  //digit_nn_predict_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  //main_digit_nn_predict();

  /* Terminate the application.
     You do not need to do this more than one time. */
  //digit_nn_predict_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
