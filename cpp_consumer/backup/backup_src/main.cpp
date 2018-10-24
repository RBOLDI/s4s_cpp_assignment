#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <stdio.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

char str [150];

int main(int argc, char* argv[])
{
    auto fileStream = std::make_shared<ostream>();
    printf("Typ hier de link waarvan u een back-up wilt maken.\n\r");
    printf("voor werknemers:\n\r");
    printf("http://localhost:3000/werknemers \n\r");
    printf("of http://localhost:3000/werknemers/1 etc... \n\n\r");
    printf("Ander voorbeeld: \n\r");
    printf("http://www.bing.com/search \n\r");
    printf("typ uw keuze: ");
    scanf("%s",str);
    // Open stream to output file.
    pplx::task<void> requestTask = fstream::open_ostream(U("backup.html")).then([=](ostream outFile)
    {
        *fileStream = outFile;

        // Create http_client to send the request.
        http_client client(U(str));

        // Build request URI and start the request.
        uri_builder builder(U(""));
        //builder.append_query(U("q"), U("cpprestsdk github"));
        return client.request(methods::GET, builder.to_string());
    })

    // Handle response headers arriving.
    .then([=](http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());

        // Write response body into the file.
        return response.body().read_to_end(fileStream->streambuf());
    })

    // Close the file stream.
    .then([=](size_t)
    {
        return fileStream->close();
    });

    // Wait for all the outstanding I/O to complete and handle any exceptions
    try
    {
        requestTask.wait();
    }
    catch (const std::exception &e)
    {
        printf("Error exception:%s\n", e.what());
    }

    return 0;
}
