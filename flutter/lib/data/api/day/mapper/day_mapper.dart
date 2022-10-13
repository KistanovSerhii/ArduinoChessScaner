import '../model/api_day.dart';
import '../../../../domain/models/day.dart';

class DayMapper {
  static Day fromApi(ApiDay day) {
    return Day(
      sunrise: StringToDateTime(day.sunrise),
      sunset: StringToDateTime(day.sunset),
      solarNoon: StringToDateTime(day.solarNoon),
      dayLength: day.dayLength.toInt(),
    );
  }
}

DateTime StringToDateTime(String day) {
  DateTime? dateValue;

  dateValue = DateTime.tryParse(day);

  return dateValue!;
}
