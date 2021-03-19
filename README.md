## Build with xmake and clang
```
sudo apt-get update
sudo apt-get install clang-tools-10
bash <(curl -fsSL https://xmake.io/shget.text)
```

## Build

```
xmake
```

## Run tests

```
xmake run test
```

## Run cli

```
echo "5 + 3 * 87" | xmake run standalone
```