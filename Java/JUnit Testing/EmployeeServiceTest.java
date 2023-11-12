package com.assignment.task.service;

import static org.junit.jupiter.api.Assertions.*;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.MockedStatic;
import org.mockito.Mockito;

import static org.mockito.Mockito.*;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.dao.DataAccessException;
import org.springframework.dao.EmptyResultDataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

import com.assignment.task.entities.Address;
import com.assignment.task.entities.Employee;
import com.assignment.task.entities.Gender;
import com.assignment.task.entities.Role;
import com.assignment.task.exception.InvalidEmployeeDetailException;
import com.assignment.task.helper.CSVHelper;
import com.assignment.task.repositories.EmployeeRepository;
import com.assignment.task.repositoriesImpl.EmployeeRepositoryImpl;
import com.assignment.task.supportingClass.ResponseDeleteRecord;
import com.assignment.task.supportingClass.ResponseGetRecord;
import com.assignment.task.supportingClass.ResponseMultipleRecordsCreated;
import com.assignment.task.supportingClass.ResponseUpdateRecords;
import com.assignment.task.validation.EmployeeValidation;

import net.bytebuddy.asm.Advice.Local;

@ExtendWith(MockitoExtension.class)
class EmployeeServiceTest {

	@Mock
	EmployeeRepositoryImpl employeeRepository;
	
	@Mock
	JdbcTemplate jdbcTemplate;
	
	@InjectMocks
	EmployeeService employeeService;
	
	@BeforeEach
	public void setup() {
	
	}
	
	
	@Test
	@DisplayName("save multiple employees")
	public void givenEmployeesList_whenMultipleEmp_thenSaveInDB() throws Exception {
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		Employee emp1 = new Employee("Mridul","Rajbhar",22,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);
		
		List<Employee> employeeList = new ArrayList<Employee>();	
		employeeList.add(emp1);
				
		Map<Integer, Employee> validEmployee = new HashMap<Integer, Employee>();
		validEmployee.put(1, emp1);
		
		ResponseMultipleRecordsCreated<Employee> response = new ResponseMultipleRecordsCreated<Employee>();
		
		try (MockedStatic<CSVHelper> csvHelper = Mockito.mockStatic(CSVHelper.class)){
			
			csvHelper
				.when(
						()->{
							CSVHelper.readingCSVFile(
									any(ResponseMultipleRecordsCreated.class)
								);
						}).thenReturn(validEmployee);
			
			for(Map.Entry<Integer, Employee> emp : validEmployee.entrySet()) {
				when(employeeRepository.saveEmployee(emp.getValue())).thenReturn(emp.getValue());
			}
			
			//when
			ResponseMultipleRecordsCreated<Employee> returnedResponseEmployees = this.employeeService.saveMultipleEmployee();
			
			//then
			assertEquals(1,returnedResponseEmployees.getSuccess().size());
		}
	}
	
	
	@Test
	@DisplayName("Save Multiple Employees negative Scenario")
	public void givenEmployeeList_whenSaveEmployees_thenReturnEmptyList() throws Exception {
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		Employee emp1 = new Employee("Mridul","Rajbhar",22,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);
		
		List<Employee> employeeList = new ArrayList<Employee>();	
		employeeList.add(emp1);
				
		Map<Integer, Employee> validEmployee = new HashMap<>();
		validEmployee.put(1, emp1);
		
		ResponseMultipleRecordsCreated<Employee> response = new ResponseMultipleRecordsCreated<Employee>();
		
		try (MockedStatic<CSVHelper> csvHelper = Mockito.mockStatic(CSVHelper.class)){
			
			csvHelper
				.when(
						()->{
							CSVHelper.readingCSVFile(
									any(ResponseMultipleRecordsCreated.class)
								);
						}).thenReturn(validEmployee);
			
			for(Map.Entry<Integer, Employee> emp : validEmployee.entrySet()) {
				doThrow(IllegalStateException.class).when(employeeRepository).saveEmployee(emp.getValue());
			}
			
			//when
			ResponseMultipleRecordsCreated<Employee> returnedResponseEmployees = this.employeeService.saveMultipleEmployee();
			
			//then
			assertEquals(1, returnedResponseEmployees.getError().get(0).getRecordNumber());
		}
	}
	
	
	
	@Test
	@DisplayName("Get Employee By Id")
	public void givenEmployeeId_whenGetEmployee_thenReturnEmployeeObj() {
		//given
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		Employee emp1 = new Employee("Mridul","Rajbhar",22,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);
		when(jdbcTemplate.queryForObject(anyString(), any(BeanPropertyRowMapper.class), anyInt())).thenReturn(emp1);
		
		//when
		Employee employeeReturned = this.employeeService.getEmployeeById(1);
		
		//then 
		assertAll(
			()->{assertNotNull(employeeReturned);},
			()->{assertEquals(emp1.getFirstname(), employeeReturned.getFirstname());}	
			);
	}
	
	
	@Test
	@DisplayName("Get Employee By Id negative scenario")
	public void givenEmployeeId_whenGetEmployee_thenReturnNull() {
		//given
		when(jdbcTemplate.queryForObject(anyString(), any(BeanPropertyRowMapper.class), anyInt())).thenThrow(EmptyResultDataAccessException.class);
		
		//when
		Employee employeeReturned = this.employeeService.getEmployeeById(1);
		
		//then 
		assertAll(
			()->{assertNull(employeeReturned);}	
			);
	}

	
	@Test
	@DisplayName("Junit test for update employees positive scenario")
	public void givenEmployeeDetails_whenUpdateEmployee_thenReturnResponseUpdateRecords() throws Exception {
		//given
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		Employee emp1 = new Employee("Mridul","Rajbhar",23,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);
		
		Address updatedAdd1 = new Address("B/6 Shalimar", "Vakola Road", "Pune", "Maharashtra","India","123456");
		Employee updatedEmp1 = new Employee("Mridul","Rajbhar",23,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		updatedEmp1.setAddress(updatedAdd1);
		
		when(employeeRepository.updateEmployee(any(Employee.class))).thenReturn(updatedEmp1);
		
		//when
		ResponseUpdateRecords returnedUpdatedEmployee =employeeService.updateEmployee(emp1);
		
		//then
		assertAll(
			()->{assertTrue(returnedUpdatedEmployee.isSuccess());});
	}
	
	
	@Test
	@DisplayName("Junit test for update employees negative scenario null returned")
	public void givenEmployeeDetails_whenUpdateEmployee_thenExceptions1() throws Exception {
		//given
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		Employee emp1 = new Employee("Mridul","Rajbhar",23,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);
		
		when(employeeRepository.updateEmployee(any(Employee.class))).thenReturn(null);
		
		//when
		ResponseUpdateRecords returnedUpdatedEmployee = employeeService.updateEmployee(emp1);
		
		//then
		assertAll(
			()->{assertFalse(returnedUpdatedEmployee.isSuccess());});
	}
	
	@Test
	@DisplayName("Junit test for update employees negative scenario null returned InvalidEmployeeDatails")
	public void givenEmployeeDetails_whenUpdateEmployee_thenExceptions() throws Exception {
		//given
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		Employee emp1 = new Employee("Mridul","Rajbhar",22,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);
		
		//when
		ResponseUpdateRecords returnedUpdatedEmployee = employeeService.updateEmployee(emp1);
		
		//then
		assertAll(
			()->{assertEquals("Age provided and calulated age through birthdate dosen't match", returnedUpdatedEmployee.getError().get(0));});
	}

	@Test
	@DisplayName("Junit test for Get Employee by Id hibernate")
	public void givenEmployeeDetails_whenGetByIdHibernate_thenReturnEmployee() throws Exception {
		//given
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		Employee emp1 = new Employee("Mridul","Rajbhar",22,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);
		
		when(employeeRepository.getEmployee(any(Integer.class))).thenReturn(emp1);
		
		//when
		ResponseGetRecord<Employee> returnedEmployee = this.employeeService.getEmployeeByIdHibernate(1);
		
		//then
		assertAll(
			()->{assertEquals(emp1, returnedEmployee.getSuccess());});
	}
	
	@Test
	@DisplayName("Junit test for Get Employee by Id hibernate for not existing employee")
	public void givenEmployeeDetails_whenGetByIdHibernate_thenReturnNullForNonExistingEmployee() throws Exception {
		//given
		
		when(employeeRepository.getEmployee(any(Integer.class))).thenReturn(null);
		
		//when
		ResponseGetRecord<Employee> returnedEmployee = this.employeeService.getEmployeeByIdHibernate(1);
		
		//then
		assertAll(
			()->{assertNull(returnedEmployee.getSuccess());},
			()->{assertEquals("no employee found with given id", returnedEmployee.getError());});
	}
	
	@Test
	@DisplayName("junit test for delete test")
	public void givenEmployee_whenDeleteEmployee_thenReturnSuccessTrue() throws Exception {
		//given
		doNothing().when(employeeRepository).deleteEmployee(any(Integer.class));
		
		ResponseDeleteRecord response = this.employeeService.deleteEmployee(1);
		
		assertTrue(response.isSuccess());
		assertEquals("no error deleted successfully", response.getErrorMessage());
	}
	
	@Test
	@DisplayName("junit test for delete test exception negative test")
	public void givenEmployee_whenDeleteEmployee_thenThrowException() throws Exception {
		//given
		doThrow(IllegalArgumentException.class).when(employeeRepository).deleteEmployee(any(Integer.class));
		
		ResponseDeleteRecord response = this.employeeService.deleteEmployee(1);
		
		assertFalse(response.isSuccess());
		assertNotEquals("no error deleted successfully", response.getErrorMessage());
	}
	
//	public void givenEmployeeDetails_
	
}
