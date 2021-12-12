#include <memory>
#include <string>

class Object {
public:
  virtual int get_type_id() = 0;
  virtual std::string to_string() = 0;
  virtual ~Object() = default;

private:
  static constexpr int id = 0;
};

class String : public Object {
public:
  String() = default;
  explicit String(const std::string &str) : data(str) {}

  virtual int get_type_id() override { return type_id; }
  virtual std::string to_string() override { return data; }
  virtual ~String() = default;
  // Implement its API later
private:
  static constexpr int type_id = 1;
  std::string data{};
};

class Integer : public Object {
public:
  Integer() = default;
  explicit Integer(int value) : data(value) {}

  virtual int get_type_id() override { return type_id; }
  virtual std::string to_string() override { return std::to_string(data); }
  virtual ~Integer() = default;
  // Implement its API later
private:
  static constexpr int type_id = 2;
  int data;
};

std::unique_ptr<Object> object_factory(std::string &&data) {
  return std::make_unique<String>(std::forward<std::string>(data));
}

std::unique_ptr<Object> object_factory(int data) {
  return std::make_unique<Integer>(std::forward<int>(data));
}
