FROM ubuntu:latest

RUN apt-get update && apt-get install -y valgrind
RUN apt-get install clang -y
RUN apt-get install make -y

WORKDIR /app

COPY . .

CMD ["sh"]
