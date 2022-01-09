#ifndef LITERAL_
#define LITERAL_

#include <memory>
#include <string>

class Object
{
public:
  virtual int get_type_id() = 0;
  virtual std::string to_string() = 0;
  virtual ~Object() = default;

private:
  static constexpr int id = 0;
};

class String : public Object
{
public:
  String() = default;
  explicit String(const std::string &str) : data(str) {}

  virtual int get_type_id() override { return type_id; }
  virtual std::string to_string() override { return data; }
  virtual ~String() = default;
  size_t length() const { return data.length(); }
  // Implement its API later
private:
  static constexpr int type_id = 1;
  std::string data{};
};

class Integer : public Object
{
public:
  Integer() = default;
  explicit Integer(const double &value) : data(value) {}

  virtual int get_type_id() override { return type_id; }
  virtual std::string to_string() override { return std::to_string(data); }
  virtual ~Integer() = default;
  // Implement its API later
private:
  static constexpr int type_id = 2;
  int data;
};

inline std::unique_ptr<Object> object_factory(const std::string &data)
{
  return std::make_unique<String>(data);
}

inline std::unique_ptr<Object> object_factory(const double &data)
{
  return std::make_unique<Integer>(data);
}

#endif // !LITERAL_