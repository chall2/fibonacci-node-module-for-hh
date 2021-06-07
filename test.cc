#include <nan.h>

int Fibonacci(int number)
{
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    return Fibonacci(number-1) + Fibonacci(number-2);
}

auto&& GetNextFibonacciIterator = []() { 
    int i = 0; 
	
    return [=]() mutable { 
        return Fibonacci(i++); 
    }; 
}();

void GetNextFibonacciNumber(const Nan::FunctionCallbackInfo<v8::Value>& info) { 
	v8::Local<v8::Number> nextNumber = Nan::New(GetNextFibonacciIterator());
	
	info.GetReturnValue().Set(nextNumber);
}

void Init(v8::Local<v8::Object> exports) {
	v8::Local<v8::Context> context = exports->CreationContext();
	exports->Set(context,
               Nan::New("GetNextFibonacciNumber").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(GetNextFibonacciNumber)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(test, Init)