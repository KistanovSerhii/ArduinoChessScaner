import './request/get_day_body.dart';
import './mapper/day_mapper.dart';
import 'package:meta/meta.dart';
import './service/sunrise_service.dart';
import '../../../domain/model/day.dart';

class ApiUtil {
  final SunriseService _sunriseService;

  ApiUtil(this._sunriseService);

  Future<Day> getDay({
    @required double latitude,
    @required double longitude,
  }) async {
    final body = GetDayBody(latitude: latitude, longitude: longitude);
    final result = await _sunriseService.getDay(body);
    return DayMapper.fromApi(result);
  }
}
