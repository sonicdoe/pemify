#include <nan.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/x509.h>

using namespace v8;

void ConvertDER(const Nan::FunctionCallbackInfo<Value>& info) {
  Local<Object> bufferObj = info[0]->ToObject();
  const char *bufferData = node::Buffer::Data(bufferObj);
  const unsigned char *uBufferData = (unsigned char *)(bufferData);
  size_t bufferLength = node::Buffer::Length(bufferObj);

  X509 *internal = d2i_X509(NULL, &uBufferData, bufferLength);

  if (internal) {
    BIO *bp = BIO_new(BIO_s_mem());

    PEM_write_bio_X509(bp, internal);

    BUF_MEM *mem = NULL;
    BIO_get_mem_ptr(bp, &mem);

    std::string pem(mem->data, mem->length);

    info.GetReturnValue().Set(Nan::New(pem).ToLocalChecked());

    BIO_free(bp);
  } else {
    Nan::ThrowError("Could not parse certificate.");
  }

  X509_free(internal);
}

void Init(Local<Object> exports) {
  exports->Set(Nan::New("der").ToLocalChecked(),
    Nan::New<FunctionTemplate>(ConvertDER)->GetFunction());
}

NODE_MODULE(der, Init)
