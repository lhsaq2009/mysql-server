//
// Created by Haisen Ling on /20235/30.
//

#ifndef MYSQL_ENUM_UTILS_H
#define MYSQL_ENUM_UTILS_H


template <typename E>
concept Enum = std::is_enum_v<E>;

template <Enum E, E V>
constexpr auto n() noexcept {
#  if defined(__clang__) || defined(__GNUC__)
  constexpr auto name = pretty_name({ __PRETTY_FUNCTION__, sizeof(__PRETTY_FUNCTION__) - 2 });
#  elif defined(_MSC_VER)
  //auto __cdecl magic_enum::detail::n<enum Color, Color::RED>(void) noexcept 去掉末尾17个再过滤开头
  constexpr auto name = pretty_name({ __FUNCSIG__, sizeof(__FUNCSIG__) - 17 });
#  endif
  return static_string<name.size()>{name};
}
template <Enum E, E V>
inline constexpr auto enum_name_v = n<E, V>();

#endif //MYSQL_ENUM_UTILS_H
